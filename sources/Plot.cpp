#include "../headers/Plot.h"
#include "../headers/FunctionData.h"
#include "../headers/Curve.h"

#include <iostream>
#include <qstring.h>
#include <qtextcodec.h>
#include <qwt_plot_panner.h>
#include <qwt_legend.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_item.h>
#include <qwt_legend_item.h>
#include <qevent.h>

using namespace std;

class Grid: public QwtPlotGrid
{
public:
    Grid()
    {
        enableXMin(true);
		enableYMin(true);
        setMajPen( QPen( Qt::white, 0, Qt::DotLine ) );
        setMinPen( QPen( Qt::gray, 0 , Qt::DotLine ) );
    }

    virtual void updateScaleDiv( const QwtScaleDiv &xMap,
        const QwtScaleDiv &yMap )
    {
        QList<double> ticksX[QwtScaleDiv::NTickTypes];

        ticksX[QwtScaleDiv::MajorTick] = 
            xMap.ticks( QwtScaleDiv::MediumTick );
        ticksX[QwtScaleDiv::MinorTick] = 
            xMap.ticks( QwtScaleDiv::MinorTick );

		QList<double> ticksY[QwtScaleDiv::NTickTypes];

        ticksY[QwtScaleDiv::MajorTick] = 
            yMap.ticks( QwtScaleDiv::MediumTick );
        ticksY[QwtScaleDiv::MinorTick] = 
            yMap.ticks( QwtScaleDiv::MinorTick );

		QwtPlotGrid::updateScaleDiv(
            QwtScaleDiv( xMap.lowerBound(), xMap.upperBound(), ticksX ),
            QwtScaleDiv( yMap.lowerBound(), yMap.upperBound(), ticksY ) );
    }
};

class MyZoomer: public QwtPlotZoomer
{
public:
    MyZoomer(QwtPlotCanvas *canvas):
        QwtPlotZoomer(canvas)
    {
        setTrackerMode(AlwaysOn);
    }

    virtual QwtText trackerTextF(const QPointF &pos) const
    {
        QColor bg(Qt::white);
        bg.setAlpha(200);

        QwtText text = QwtPlotZoomer::trackerTextF(pos);
        text.setBackgroundBrush( QBrush( bg ));
        return text;
    }
};

Plot::Plot(QWidget *parent, int _type):
    QwtPlot( parent ), type(_type)
{
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1250"));		//tu trzeba poprawi� dla innych system�w
	setObjectName("Por�wnanie krzywych");
	if(type == 0)
		setTitle("Por�wnanie krzywych ROC");
	else
		setTitle("Por�wnanie krzywych PR");

	const int qtc[] = { 3,2,7,13,8,14,9, 15, 10, 16, 11, 17, 12, 18, 5, 4, 6, 19, 0, 1 };
	itColor = 0;
	QtColors = qtc;

    setAutoFillBackground( true );
    setPalette(QPalette(QColor(185, 213, 248)));
    //updateGradient();

	legend = new QwtLegend;
    legend->setItemMode(QwtLegend::CheckableItem);
    insertLegend(legend, QwtPlot::RightLegend);

	connect(this, SIGNAL(curveAdd()), SLOT(cAdded()));
    connect(this, SIGNAL(legendChecked(QwtPlotItem *, bool)), SLOT(showItem(QwtPlotItem *, bool)));

    //replot(); // creating the legend items	
    setAutoReplot(true);

    // axes 
    if(type == 0) {
		setAxisTitle(xBottom, "False Positive Rate" );
		setAxisTitle(yLeft, "True Positive Rate");
	}
	else {
		setAxisTitle(xBottom, "Recall" );
		setAxisTitle(yLeft, "Precision");
	}

	setAxisScale(xBottom, 0.0, 1.0);
    setAxisScale(yLeft, 0.0, 1.0);

	grid = new Grid;
    grid->attach(this);

	// LeftButton for the zooming
    // MidButton for the panning
    // RightButton: zoom out by 1
    // Ctrl+RighButton: zoom out to full size

    QwtPlotZoomer* zoomer = new MyZoomer( canvas() );
	zoomer->setRubberBandPen( QColor( Qt::black ) );
    zoomer->setTrackerPen( QColor( Qt::black ) );
    zoomer->setMousePattern( QwtEventPattern::MouseSelect2,
        Qt::RightButton, Qt::ControlModifier );
    zoomer->setMousePattern( QwtEventPattern::MouseSelect3,
        Qt::RightButton );

	QwtPlotPanner *panner = new QwtPlotPanner( canvas() );
    panner->setMouseButton( Qt::MidButton );

	// canvas
    canvas()->setLineWidth( 1 );
    canvas()->setFrameStyle( QFrame::Box | QFrame::Plain );
    canvas()->setBorderRadius( 15 );

    QPalette canvasPalette( Qt::white );
    canvasPalette.setColor( QPalette::Foreground, QColor( 133, 190, 232 ) );
    canvas()->setPalette( canvasPalette );

	QWidget::setMouseTracking(true);
	installEventFilter(this);
	
	curve_counter=0;
}

int Plot::addCurve(QString fileName, int _type, double _auc)
{	
int atchn=0;
for (int i=0; i<curves_.size(); i++){
	if ((curves_[i])->attached){
		atchn++;
	}
}
qDebug()<<"attached1:"<<atchn;


	ProxyFile *_proxy;
	QColor color;
	QString name;
	Curve *curve;

	bool exists=false;
	for (int i=0; i<proxies_.size(); i++){
		if ((proxies_[i])->real_file_path==fileName){
		qDebug()<<"already exists";
			curve=(curves_[i]);
			
			
			if (curve->attached){
			qDebug()<<"already attached";
				return 0;
			}
			
			exists=true;
			
			_proxy=proxies_[i];
			(curves_[i])->attach(this);
			color = (curves_[i])->getColor();
			name = ((curves_[i])->getTitle()).text();
			curve->attached=true;
		}
	}




/*
	if (curve_counter>=CURVE_LIMIT){
		for (int i=0; i<curves_.size(); i++){
			if ((curves_[i])->deleted){
				delete curves_[i];
				curves_.erase(curves_.begin()+i);
				delete proxies_[i];
				proxies_.erase(proxies_.begin()+i);
				break;
			}
		}
	}
	if (curve_counter>=CURVE_LIMIT){
	//too many curves, error message
		return;
	}
*/





if (exists==false){
qDebug()<<"loading";

	name = generateName();
	curve = new Curve(name);
	curve->attached=true;
	//curve->setLegendAttribute(QwtPlotCurve::LegendShowLine, true);
	curve->setRenderHint(QwtPlotItem::RenderAntialiased);

	color = generateColor();
	curve->setPen(QPen(color));
    curve->attach(this);
    
/*
	if(itColor%2 == 0) {
		curve->setData(new FunctionData(::sin));
	}
	else {
		curve->setData(new FunctionData(::cos));
	}
	
	ProxyFile *_proxy
*/
	
		qDebug()<<"DOESNT EXIST";
		_proxy = new ProxyFile(fileName);
	
	QVector<QPointF>* dPoints;
	dPoints=_proxy->getData();

	curve->setData(new FunctionData(dPoints));	

	

	curve->init(_type, _auc, color);
	curves_.push_back(curve);
	proxies_.push_back(_proxy);
	
}

curve->position=(itemList(QwtPlotItem::Rtti_PlotCurve)).size()-1;
	qDebug()<<"curve position:"<<curve->position;
	
curve_counter++;
qDebug()<<"QwtPlotItemList items = itemList(QwtPlotItem::Rtti_PlotCurve)";
	QwtPlotItemList items = itemList(QwtPlotItem::Rtti_PlotCurve);
	for ( int i = 0; i < items.size(); i++ )
    {
		if ( i == items.size() - 1 )
        {
			QwtLegendItem *legendItem = (QwtLegendItem *)legend->find(items[i]);
            if ( legendItem )
                legendItem->setChecked(true);
            items[i]->setVisible(true);
        }
    }
qDebug()<<"emit";
	emit curveAdded(name, color, _auc);
	//emit curveAdd();
	
	qDebug()<<"emited cc:"<<curve_counter;
	
	

		
	
	
atchn=0;
for (int i=0; i<curves_.size(); i++){
	if ((curves_[i])->attached){
		atchn++;
	}
}
qDebug()<<"attached2:"<<atchn;

	
	return 0;
}

int Plot::modifyCurveColor(int _id, QColor color)
{
	vector<Curve*>::iterator it;
	for(it = curves_.begin(); it != curves_.end(); ++it) 
	{
		if((*it)->getId() == _id) {
			(*it)->setPen(color);
		}
	}
	return 0;
}

QColor Plot::generateColor()
{
	QColor color;
	color.setRgb(QtColors[itColor]);
	itColor++;
	if(itColor == sizeof(QtColors)) {
		itColor = 0;
	}
	return color;
}

QString Plot::generateName()
{
	int curveNr = curves_.size() + 1;
	QString name = QString("krzywa_%1").arg(curveNr);
	return name;
}

void Plot::insertMarkers()
{
	//  ...a horizontal line at y = 0...
    QwtPlotMarker *mY = new QwtPlotMarker();
    mY->setLabel(QString::fromLatin1("y = 0"));
    mY->setLabelAlignment(Qt::AlignRight|Qt::AlignTop);
    mY->setLineStyle(QwtPlotMarker::HLine);
    mY->setYValue(0.0);
    mY->attach(this);

    //  ...a vertical line at x = 2 * pi
    QwtPlotMarker *mX = new QwtPlotMarker();
    mX->setLabel(QString::fromLatin1("x = 2 pi"));
    mX->setLabelAlignment(Qt::AlignLeft | Qt::AlignBottom);
    mX->setLabelOrientation(Qt::Vertical);
    mX->setLineStyle(QwtPlotMarker::VLine);
    mX->setLinePen(QPen(Qt::black, 0, Qt::DashDotLine));
    mX->setXValue(2.0 * M_PI);
    mX->attach(this);
}

void Plot::updateGradient()
{
	//zabawy z gradientowym wy�wietlaniem kolor�w

    QPalette pal = palette();

    const QColor buttonColor = pal.color( QPalette::Button );

#ifdef Q_WS_X11
    // Qt 4.7.1: QGradient::StretchToDeviceMode is buggy on X11

    QLinearGradient gradient( rect().topLeft(), rect().bottomLeft() );
    gradient.setColorAt( 0.0, Qt::white );
    gradient.setColorAt( 0.7, buttonColor );
    gradient.setColorAt( 1.0, buttonColor );
#else
    QLinearGradient gradient( 0, 0, 0, 1 );
    gradient.setCoordinateMode( QGradient::StretchToDeviceMode );
    gradient.setColorAt( 0.0, Qt::white );
    gradient.setColorAt( 0.7, buttonColor );
    gradient.setColorAt( 1.0, buttonColor );
#endif

    pal.setBrush( QPalette::Window, gradient );
    setPalette( pal );
}

void Plot::resizeEvent( QResizeEvent *event )
{
    QwtPlot::resizeEvent( event );
#ifdef Q_WS_X11
    //updateGradient();
#endif
}

void Plot::refreshEvent()
{
	replot();
}

bool Plot::eventFilter(QObject *obj, QEvent *event)
{
	if(event->type() == QEvent::MouseMove)
  {
    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
	emit coordinatesAssembled(mouseEvent->pos());
  }
  return false;
}

void Plot::showItem(QwtPlotItem *item, bool on)
{
	item->setVisible(on);
}

void Plot::cAdded(void)
{
	/*QwtPlotItemList items = itemList(QwtPlotItem::Rtti_PlotCurve);
	for ( int i = 0; i < items.size(); i++ )
    {
		if ( i == items.size() - 1 )
        {
			QwtLegendItem *legendItem = (QwtLegendItem *)legend->find(items[i]);
            if ( legendItem )
                legendItem->setChecked(true);
            items[i]->setVisible(true);
        }
    }*/
}

void Plot::changeName(int _pos, QString _newName)
{
	QwtPlotItemList items = itemList(QwtPlotItem::Rtti_PlotCurve);
	items[_pos]->setTitle(_newName);
	legend->repaint();
}

void Plot::changeColor(QString _name, QColor _newColor)
{
	QwtPlotItemList items = itemList(QwtPlotItem::Rtti_PlotCurve);
	vector<Curve*>::const_iterator it;
	for(it = curves_.begin(); it != curves_.end(); ++it) 
	{	
		if((*it)->title() == _name) {
			(*it)->setPen(_newColor);
		}
	}
	legend->repaint();
}

void Plot::getColAuc(QString _name)
{
	QColor color;
	double auc;
	QwtPlotItemList items = itemList(QwtPlotItem::Rtti_PlotCurve);
	vector<Curve*>::const_iterator it;
	for(it = curves_.begin(); it != curves_.end(); ++it) 
	{	
		if((*it)->title() == _name) {
			color = (*it)->getColor();
			auc = (*it)->getAUC();
		}
	}
	emit resendColorAuc(color, auc);
}

void Plot::deleteCurve(int _id)								//usuni�cie krzywej o danym id
{
qDebug()<<"DETACH curve id:"<<_id;
	
	QwtPlotItemList items = itemList(QwtPlotItem::Rtti_PlotCurve);
	qDebug()<<items.size()<<" count pre:"<<curve_counter<<" "<<curves_.size()<<"  "<<proxies_.size();
	items[_id]->detach();
	
	//curves_[_id]->attached=false;
	legend->repaint();
	curve_counter--;
	replot();	
	qDebug()<<"curve counter:"<<curve_counter;
	
	int atchn=0;
	for (int i=0; i<curves_.size(); i++){
		if ((curves_[i])->position==_id){
			curves_[i]->attached=false;
		}
		if (curves_[i]->position>_id){
			curves_[i]->position--;
		}
	}
	for (int i=0; i<curves_.size(); i++){
		if ((curves_[i])->attached){
			atchn++;
		}
	}
qDebug()<<"DELETE number of attached:"<<atchn;
	
	
	
}

void Plot::leaveOneUnhided(int _pos)
{
	QwtPlotItemList items = itemList(QwtPlotItem::Rtti_PlotCurve);
	for(int i = 0; i < items.size(); i++)
    {
		QwtLegendItem *legendItem = (QwtLegendItem *)legend->find(items[i]);
		if(i == _pos)
        {
            if(legendItem)
                legendItem->setChecked(true);
            items[i]->setVisible(true);
        }
		else {
			if(legendItem)
                legendItem->setChecked(false);
			items[i]->setVisible(false);
		}
    }
}

void Plot::clearAll()
{
	QwtPlotItemList items = itemList(QwtPlotItem::Rtti_PlotCurve);
	for(int i = 0; i < items.size(); i++)
    {
		QwtLegendItem *legendItem = (QwtLegendItem *)legend->find(items[i]);
		if(legendItem) {
			legendItem->setChecked(false);
		}
		items[i]->detach();
	}
	legend->repaint();
	replot();
}

void Plot::modifyBackgroundColor(QColor _color)
{
	setPalette(QPalette(_color));
	replot();
}

void Plot::changePlotName(QString _name)
{
	setTitle(_name);
	replot();
}

void Plot::changePlotLabels(QString _labelX, QString _labelY)
{
	setAxisTitle(xBottom, _labelX);
	setAxisTitle(yLeft, _labelY);
	replot();
}

void Plot::changeGridState(int _state)
{
	if(_state == 0)
		grid->detach();
	else
		grid->attach(this);
	replot();
}
