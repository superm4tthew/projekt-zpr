#############################################################################
# Makefile for building: projekt-zpr
# Generated by qmake (2.01a) (Qt 4.8.0) on: Cz 10. maj 00:27:50 2012
# Project:  projekt-zpr.pro
# Template: app
# Command: c:\Qt\4.8.0\bin\qmake.exe -o Makefile projekt-zpr.pro
#############################################################################

first: debug
install: debug-install
uninstall: debug-uninstall
MAKEFILE      = Makefile
QMAKE         = c:\Qt\4.8.0\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = move
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
SUBTARGETS    =  \
		debug \
		release

debug: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: projekt-zpr.pro  c:\Qt\4.8.0\mkspecs\win32-msvc2010\qmake.conf c:\Qt\4.8.0\mkspecs\qconfig.pri \
		c:\Qt\4.8.0\mkspecs\features\qt_functions.prf \
		c:\Qt\4.8.0\mkspecs\features\qt_config.prf \
		c:\Qt\4.8.0\mkspecs\features\exclusive_builds.prf \
		c:\Qt\4.8.0\mkspecs\features\default_pre.prf \
		c:\Qt\4.8.0\mkspecs\features\win32\default_pre.prf \
		c:\Qt\4.8.0\mkspecs\features\debug.prf \
		c:\Qt\4.8.0\mkspecs\features\debug_and_release.prf \
		c:\Qt\4.8.0\mkspecs\features\default_post.prf \
		c:\Qt\4.8.0\mkspecs\features\win32\default_post.prf \
		c:\Qt\4.8.0\mkspecs\features\win32\rtti.prf \
		c:\Qt\4.8.0\mkspecs\features\win32\exceptions.prf \
		c:\Qt\4.8.0\mkspecs\features\win32\stl.prf \
		c:\Qt\4.8.0\mkspecs\features\static.prf \
		c:\Qt\4.8.0\mkspecs\features\win32\embed_manifest_exe.prf \
		c:\Qt\4.8.0\mkspecs\features\win32\embed_manifest_dll.prf \
		c:\Qt\4.8.0\mkspecs\features\warn_on.prf \
		c:\Qt\4.8.0\mkspecs\features\qt.prf \
		c:\Qt\4.8.0\mkspecs\features\win32\thread.prf \
		c:\Qt\4.8.0\mkspecs\features\moc.prf \
		c:\Qt\4.8.0\mkspecs\features\win32\windows.prf \
		c:\Qt\4.8.0\mkspecs\features\resources.prf \
		c:\Qt\4.8.0\mkspecs\features\uic.prf \
		c:\Qt\4.8.0\mkspecs\features\yacc.prf \
		c:\Qt\4.8.0\mkspecs\features\lex.prf \
		c:\Qt\4.8.0\mkspecs\features\include_source_dir.prf \
		c:\Qt\4.8.0\lib\qtmaind.prl \
		c:\Qt\4.8.0\lib\QtGui.prl \
		c:\Qt\4.8.0\lib\QtCore.prl
	$(QMAKE) -o Makefile projekt-zpr.pro
c:\Qt\4.8.0\mkspecs\qconfig.pri:
c:\Qt\4.8.0\mkspecs\features\qt_functions.prf:
c:\Qt\4.8.0\mkspecs\features\qt_config.prf:
c:\Qt\4.8.0\mkspecs\features\exclusive_builds.prf:
c:\Qt\4.8.0\mkspecs\features\default_pre.prf:
c:\Qt\4.8.0\mkspecs\features\win32\default_pre.prf:
c:\Qt\4.8.0\mkspecs\features\debug.prf:
c:\Qt\4.8.0\mkspecs\features\debug_and_release.prf:
c:\Qt\4.8.0\mkspecs\features\default_post.prf:
c:\Qt\4.8.0\mkspecs\features\win32\default_post.prf:
c:\Qt\4.8.0\mkspecs\features\win32\rtti.prf:
c:\Qt\4.8.0\mkspecs\features\win32\exceptions.prf:
c:\Qt\4.8.0\mkspecs\features\win32\stl.prf:
c:\Qt\4.8.0\mkspecs\features\static.prf:
c:\Qt\4.8.0\mkspecs\features\win32\embed_manifest_exe.prf:
c:\Qt\4.8.0\mkspecs\features\win32\embed_manifest_dll.prf:
c:\Qt\4.8.0\mkspecs\features\warn_on.prf:
c:\Qt\4.8.0\mkspecs\features\qt.prf:
c:\Qt\4.8.0\mkspecs\features\win32\thread.prf:
c:\Qt\4.8.0\mkspecs\features\moc.prf:
c:\Qt\4.8.0\mkspecs\features\win32\windows.prf:
c:\Qt\4.8.0\mkspecs\features\resources.prf:
c:\Qt\4.8.0\mkspecs\features\uic.prf:
c:\Qt\4.8.0\mkspecs\features\yacc.prf:
c:\Qt\4.8.0\mkspecs\features\lex.prf:
c:\Qt\4.8.0\mkspecs\features\include_source_dir.prf:
c:\Qt\4.8.0\lib\qtmaind.prl:
c:\Qt\4.8.0\lib\QtGui.prl:
c:\Qt\4.8.0\lib\QtCore.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -o Makefile projekt-zpr.pro

qmake_all: FORCE

make_default: debug-make_default release-make_default FORCE
make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
	-$(DEL_FILE) ".\projekt-zpr.intermediate.manifest"
	-$(DEL_FILE) projekt-zpr.ilk
	-$(DEL_FILE) vc*.pdb
	-$(DEL_FILE) vc*.idb
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) projekt-zpr.pdb

check: first

debug-mocclean: $(MAKEFILE).Debug
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean: $(MAKEFILE).Release
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables: $(MAKEFILE).Debug
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables: $(MAKEFILE).Release
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
