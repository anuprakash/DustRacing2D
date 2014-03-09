# Qt project file to cross-compile the editor for Windows with MXE

TEMPLATE = app
TARGET   = dustrac-editor

DEFINES += DATA_PATH=\\\"./data\\\" VERSION=\\\"1.7.1\\\"
QMAKE_CXXFLAGS += -std=gnu++11

# Qt version check
message("Building for Qt version $${QT_VERSION}.")
contains(QT_VERSION, ^5\\..*) {
QT += widgets xml
DEFINES += USE_QT5
} else {
QT += gui xml
}

INCLUDEPATH += .

# Input
HEADERS +=  \
    ../common/config.hpp \
    ../common/mapbase.hpp \
    ../common/objectbase.hpp \
    ../common/objects.hpp \
    ../common/route.hpp \
    ../common/targetnodebase.hpp \
    ../common/trackdatabase.hpp \
    ../common/tracktilebase.hpp \
    aboutdlg.hpp \
    editordata.hpp \
    editorscene.hpp \
    editorview.hpp \
    mainwindow.hpp \
    map.hpp \
    newtrackdialog.hpp \
    object.hpp \
    objectfactory.hpp \
    objectmodel.hpp \
    objectmodelloader.hpp \
    rotatedialog.hpp \
    rotatetileundostackitem.hpp \
    targetnode.hpp \
    targetnodesizedlg.hpp \
    tileanimator.hpp \
    tiletypedialog.hpp \
    tiletypeundostackitem.hpp \
    trackdata.hpp \
    trackio.hpp \
    trackpropertiesdialog.hpp \
    tracktile.hpp \
    undostackitembase.hpp \

SOURCES += \
    ../common/config.cpp \
    ../common/mapbase.cpp \
    ../common/objectbase.cpp \
    ../common/objects.cpp \
    ../common/route.cpp \
    ../common/targetnodebase.cpp \
    ../common/trackdatabase.cpp \
    ../common/tracktilebase.cpp \
    aboutdlg.cpp \
    editordata.cpp \
    editorscene.cpp \
    editorview.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    newtrackdialog.cpp \
    object.cpp \
    objectfactory.cpp \
    objectmodelloader.cpp \
    rotatedialog.cpp \
    rotatetileundostackitem.cpp \
    targetnode.cpp \
    targetnodesizedlg.cpp \
    tileanimator.cpp \
    tiletypedialog.cpp \
    tiletypeundostackitem.cpp \
    trackdata.cpp \
    trackio.cpp \
    trackpropertiesdialog.cpp \
    tracktile.cpp \

RESOURCES += ../../data/icons/icons.qrc ../../data/images/editor.qrc
RC_FILE = ../../data/icons/WindowsEditor.rc
TRANSLATIONS += \
    translations/dustrac-editor_fi.ts \
    translations/dustrac-editor_it.ts \
    translations/dustrac-editor_cs.ts 

target.path = $$OUT_PWD/../..
INSTALLS += target

