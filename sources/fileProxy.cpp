/**
 * @file
 * @author  Szymon Piątek, Mateusz Matuszewski
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 * The ProxyFile class and RealFile class are implementation of Proxy Design
 * Pattern with lazy reading.
 */



#include "../headers/fileProxy.h"
#include <QFile>

		
/**
 * Constructor of RealFile class
 * @param _path path of file
 */
RealFile::RealFile(QString _path){
	path=_path;
}

		
/**
 * Destructor of RealFile class
 */
RealFile::~RealFile(){}

		
/**
 * Loads data from file which name is stored in path field of the RealFile class
 * @return	pointer to vector storing QPointF objects which represent coordinates
 *			of point
 */
QVector<QPointF>* RealFile::getData(){
	//read from file
	QFile file(path);
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream in(&file);
	QString line;
	
	while (!in.atEnd()) {
		line= in.readLine();
		QStringList field = line.split("\t", QString::SkipEmptyParts);
		if (field.size()!=2){
			if(field.size()==0){
				break;
			}
			else{
				throw 1001;
			}
		}
		bool error_x, error_y;
		double data_x=field.at(0).toDouble(&error_x);
		double data_y=field.at(1).toDouble(&error_y);
		
		if (!error_x||!error_y){
			throw 1002;
		}
		data_points.append( QPointF( data_x, data_y) );	
	}
	return &data_points;
}

ProxyFile::ProxyFile(){}
		
/**
 * Constructor of ProxyFile class
 * @param _path path of file
 */
ProxyFile::ProxyFile(QString _path){
	real_file_path=_path;
	p_real_file=0;
}

/**
 * Destructor of ProxyFile class. Deletes pointer to RealFile class
 */
ProxyFile::~ProxyFile(){
	delete p_real_file;
}

/**
 * Initialization function
 * @param _path path of file
 */
ProxyFile* ProxyFile::init_path(QString _path){
	if (!p_real_file){
		delete p_real_file;
	}
	real_file_path=_path;
	return this;
}

/**
 * Creates new RealFile object if necessary and assign it to p_real_file pointer
 */
QVector<QPointF>* ProxyFile::getData(){
	if (!p_real_file){
		p_real_file= new RealFile(real_file_path);
	}
	return p_real_file->getData();
}

