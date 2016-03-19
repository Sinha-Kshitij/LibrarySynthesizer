/****************************************************************************
** Meta object code from reading C++ file 'classcombineruserinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../classcombineruserinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'classcombineruserinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HeaderAndSourceTypesDialog_t {
    QByteArrayData data[14];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HeaderAndSourceTypesDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HeaderAndSourceTypesDialog_t qt_meta_stringdata_HeaderAndSourceTypesDialog = {
    {
QT_MOC_LITERAL(0, 0, 26), // "HeaderAndSourceTypesDialog"
QT_MOC_LITERAL(1, 27, 11), // "updateTypes"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 16), // "QVector<QString>"
QT_MOC_LITERAL(4, 57, 11), // "headerTypes"
QT_MOC_LITERAL(5, 69, 11), // "sourceTypes"
QT_MOC_LITERAL(6, 81, 10), // "hideOrOpen"
QT_MOC_LITERAL(7, 92, 6), // "ignore"
QT_MOC_LITERAL(8, 99, 4), // "open"
QT_MOC_LITERAL(9, 104, 22), // "addHeaderTypesFunction"
QT_MOC_LITERAL(10, 127, 22), // "addSourceTypesFunction"
QT_MOC_LITERAL(11, 150, 25), // "removeHeaderTypesFunction"
QT_MOC_LITERAL(12, 176, 25), // "removeSourceTypesFunction"
QT_MOC_LITERAL(13, 202, 14) // "rejectFunction"

    },
    "HeaderAndSourceTypesDialog\0updateTypes\0"
    "\0QVector<QString>\0headerTypes\0sourceTypes\0"
    "hideOrOpen\0ignore\0open\0addHeaderTypesFunction\0"
    "addSourceTypesFunction\0removeHeaderTypesFunction\0"
    "removeSourceTypesFunction\0rejectFunction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HeaderAndSourceTypesDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   59,    2, 0x0a /* Public */,
       8,    2,   62,    2, 0x0a /* Public */,
       9,    1,   67,    2, 0x08 /* Private */,
      10,    1,   70,    2, 0x08 /* Private */,
      11,    1,   73,    2, 0x08 /* Private */,
      12,    1,   76,    2, 0x08 /* Private */,
      13,    1,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void HeaderAndSourceTypesDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HeaderAndSourceTypesDialog *_t = static_cast<HeaderAndSourceTypesDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateTypes((*reinterpret_cast< QVector<QString>(*)>(_a[1])),(*reinterpret_cast< QVector<QString>(*)>(_a[2]))); break;
        case 1: _t->hideOrOpen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->open((*reinterpret_cast< QVector<QString>(*)>(_a[1])),(*reinterpret_cast< QVector<QString>(*)>(_a[2]))); break;
        case 3: _t->addHeaderTypesFunction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->addSourceTypesFunction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->removeHeaderTypesFunction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->removeSourceTypesFunction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->rejectFunction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HeaderAndSourceTypesDialog::*_t)(QVector<QString> , QVector<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HeaderAndSourceTypesDialog::updateTypes)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject HeaderAndSourceTypesDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_HeaderAndSourceTypesDialog.data,
      qt_meta_data_HeaderAndSourceTypesDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HeaderAndSourceTypesDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HeaderAndSourceTypesDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HeaderAndSourceTypesDialog.stringdata0))
        return static_cast<void*>(const_cast< HeaderAndSourceTypesDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int HeaderAndSourceTypesDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void HeaderAndSourceTypesDialog::updateTypes(QVector<QString> _t1, QVector<QString> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ClassCombinerUserInterface_t {
    QByteArrayData data[56];
    char stringdata0[843];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClassCombinerUserInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClassCombinerUserInterface_t qt_meta_stringdata_ClassCombinerUserInterface = {
    {
QT_MOC_LITERAL(0, 0, 26), // "ClassCombinerUserInterface"
QT_MOC_LITERAL(1, 27, 7), // "addFile"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 6), // "ignore"
QT_MOC_LITERAL(4, 43, 4), // "file"
QT_MOC_LITERAL(5, 48, 9), // "addFileUI"
QT_MOC_LITERAL(6, 58, 10), // "removeFile"
QT_MOC_LITERAL(7, 69, 9), // "addFolder"
QT_MOC_LITERAL(8, 79, 11), // "folderToAdd"
QT_MOC_LITERAL(9, 91, 11), // "addFolderUI"
QT_MOC_LITERAL(10, 103, 6), // "folder"
QT_MOC_LITERAL(11, 110, 12), // "removeFolder"
QT_MOC_LITERAL(12, 123, 18), // "checkForDegeneracy"
QT_MOC_LITERAL(13, 142, 24), // "checkForFolderDegeneracy"
QT_MOC_LITERAL(14, 167, 18), // "checkForHeaderType"
QT_MOC_LITERAL(15, 186, 4), // "text"
QT_MOC_LITERAL(16, 191, 18), // "checkForSourceType"
QT_MOC_LITERAL(17, 210, 15), // "recursiveSearch"
QT_MOC_LITERAL(18, 226, 12), // "sourceFolder"
QT_MOC_LITERAL(19, 239, 31), // "findAllHeadersAndSourcesLocally"
QT_MOC_LITERAL(20, 271, 15), // "folderNameInput"
QT_MOC_LITERAL(21, 287, 9), // "shortName"
QT_MOC_LITERAL(22, 297, 13), // "filterChanged"
QT_MOC_LITERAL(23, 311, 11), // "sortFolders"
QT_MOC_LITERAL(24, 323, 9), // "sortFiles"
QT_MOC_LITERAL(25, 333, 17), // "folderNameDisplay"
QT_MOC_LITERAL(26, 351, 16), // "filesNameDisplay"
QT_MOC_LITERAL(27, 368, 16), // "selectHeaderFile"
QT_MOC_LITERAL(28, 385, 16), // "selectSourceFile"
QT_MOC_LITERAL(29, 402, 24), // "fileTypeSelectorFunction"
QT_MOC_LITERAL(30, 427, 20), // "fileSelectorFunction"
QT_MOC_LITERAL(31, 448, 17), // "dependencyDisplay"
QT_MOC_LITERAL(32, 466, 22), // "dependencySolutionList"
QT_MOC_LITERAL(33, 489, 16), // "assignDependency"
QT_MOC_LITERAL(34, 506, 21), // "addDependencyFunction"
QT_MOC_LITERAL(35, 528, 25), // "ensureStructuralCoherence"
QT_MOC_LITERAL(36, 554, 14), // "indexOfRemoval"
QT_MOC_LITERAL(37, 569, 10), // "analyzeAll"
QT_MOC_LITERAL(38, 580, 10), // "synthesize"
QT_MOC_LITERAL(39, 591, 11), // "analyzeFile"
QT_MOC_LITERAL(40, 603, 9), // "fileInput"
QT_MOC_LITERAL(41, 613, 20), // "indexWithinStructure"
QT_MOC_LITERAL(42, 634, 23), // "analyzeIncludeStatement"
QT_MOC_LITERAL(43, 658, 20), // "findFileDependencies"
QT_MOC_LITERAL(44, 679, 5), // "index"
QT_MOC_LITERAL(45, 685, 10), // "openDialog"
QT_MOC_LITERAL(46, 696, 19), // "convertVectorToList"
QT_MOC_LITERAL(47, 716, 16), // "QVector<QString>"
QT_MOC_LITERAL(48, 733, 17), // "dataToBeConverted"
QT_MOC_LITERAL(49, 751, 13), // "themeFunction"
QT_MOC_LITERAL(50, 765, 15), // "refreshFunction"
QT_MOC_LITERAL(51, 781, 11), // "updateTypes"
QT_MOC_LITERAL(52, 793, 17), // "headersTypesInput"
QT_MOC_LITERAL(53, 811, 16), // "sourceTypesInput"
QT_MOC_LITERAL(54, 828, 8), // "setState"
QT_MOC_LITERAL(55, 837, 5) // "state"

    },
    "ClassCombinerUserInterface\0addFile\0\0"
    "ignore\0file\0addFileUI\0removeFile\0"
    "addFolder\0folderToAdd\0addFolderUI\0"
    "folder\0removeFolder\0checkForDegeneracy\0"
    "checkForFolderDegeneracy\0checkForHeaderType\0"
    "text\0checkForSourceType\0recursiveSearch\0"
    "sourceFolder\0findAllHeadersAndSourcesLocally\0"
    "folderNameInput\0shortName\0filterChanged\0"
    "sortFolders\0sortFiles\0folderNameDisplay\0"
    "filesNameDisplay\0selectHeaderFile\0"
    "selectSourceFile\0fileTypeSelectorFunction\0"
    "fileSelectorFunction\0dependencyDisplay\0"
    "dependencySolutionList\0assignDependency\0"
    "addDependencyFunction\0ensureStructuralCoherence\0"
    "indexOfRemoval\0analyzeAll\0synthesize\0"
    "analyzeFile\0fileInput\0indexWithinStructure\0"
    "analyzeIncludeStatement\0findFileDependencies\0"
    "index\0openDialog\0convertVectorToList\0"
    "QVector<QString>\0dataToBeConverted\0"
    "themeFunction\0refreshFunction\0updateTypes\0"
    "headersTypesInput\0sourceTypesInput\0"
    "setState\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClassCombinerUserInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  219,    2, 0x08 /* Private */,
       1,    1,  222,    2, 0x08 /* Private */,
       5,    1,  225,    2, 0x08 /* Private */,
       6,    1,  228,    2, 0x08 /* Private */,
       7,    1,  231,    2, 0x08 /* Private */,
       7,    1,  234,    2, 0x08 /* Private */,
       9,    1,  237,    2, 0x08 /* Private */,
      11,    1,  240,    2, 0x08 /* Private */,
      12,    1,  243,    2, 0x08 /* Private */,
      13,    1,  246,    2, 0x08 /* Private */,
      14,    1,  249,    2, 0x08 /* Private */,
      16,    1,  252,    2, 0x08 /* Private */,
      17,    1,  255,    2, 0x08 /* Private */,
      19,    1,  258,    2, 0x08 /* Private */,
      21,    1,  261,    2, 0x08 /* Private */,
      22,    1,  264,    2, 0x08 /* Private */,
      23,    1,  267,    2, 0x08 /* Private */,
      24,    1,  270,    2, 0x08 /* Private */,
      25,    1,  273,    2, 0x08 /* Private */,
      26,    1,  276,    2, 0x08 /* Private */,
      27,    1,  279,    2, 0x08 /* Private */,
      28,    1,  282,    2, 0x08 /* Private */,
      29,    1,  285,    2, 0x08 /* Private */,
      30,    1,  288,    2, 0x08 /* Private */,
      31,    1,  291,    2, 0x08 /* Private */,
      32,    1,  294,    2, 0x08 /* Private */,
      33,    1,  297,    2, 0x08 /* Private */,
      34,    1,  300,    2, 0x08 /* Private */,
      35,    0,  303,    2, 0x08 /* Private */,
      35,    1,  304,    2, 0x08 /* Private */,
      37,    1,  307,    2, 0x08 /* Private */,
      38,    1,  310,    2, 0x08 /* Private */,
      39,    2,  313,    2, 0x08 /* Private */,
      42,    1,  318,    2, 0x08 /* Private */,
      43,    1,  321,    2, 0x08 /* Private */,
      45,    1,  324,    2, 0x08 /* Private */,
      46,    1,  327,    2, 0x08 /* Private */,
      49,    1,  330,    2, 0x08 /* Private */,
      50,    1,  333,    2, 0x08 /* Private */,
      51,    2,  336,    2, 0x08 /* Private */,
      54,    1,  341,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Bool, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Bool, QMetaType::QString,    4,
    QMetaType::Bool, QMetaType::QString,   10,
    QMetaType::Bool, QMetaType::QString,   15,
    QMetaType::Bool, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::QString, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   36,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   40,   41,
    QMetaType::QString, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::QStringList, 0x80000000 | 47,   48,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 47, 0x80000000 | 47,   52,   53,
    QMetaType::Void, QMetaType::Int,   55,

       0        // eod
};

void ClassCombinerUserInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClassCombinerUserInterface *_t = static_cast<ClassCombinerUserInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->addFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->addFileUI((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->removeFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->addFolder((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: { bool _r = _t->addFolder((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->addFolderUI((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->removeFolder((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: { bool _r = _t->checkForDegeneracy((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { bool _r = _t->checkForFolderDegeneracy((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->checkForHeaderType((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->checkForSourceType((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: _t->recursiveSearch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->findAllHeadersAndSourcesLocally((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: { QString _r = _t->shortName((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 15: _t->filterChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->sortFolders((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->sortFiles((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->folderNameDisplay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->filesNameDisplay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->selectHeaderFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->selectSourceFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->fileTypeSelectorFunction((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->fileSelectorFunction((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->dependencyDisplay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: _t->dependencySolutionList((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->assignDependency((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->addDependencyFunction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->ensureStructuralCoherence(); break;
        case 29: _t->ensureStructuralCoherence((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->analyzeAll((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->synthesize((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->analyzeFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 33: { QString _r = _t->analyzeIncludeStatement((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 34: _t->findFileDependencies((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->openDialog((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: { QStringList _r = _t->convertVectorToList((*reinterpret_cast< QVector<QString>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 37: _t->themeFunction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->refreshFunction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->updateTypes((*reinterpret_cast< QVector<QString>(*)>(_a[1])),(*reinterpret_cast< QVector<QString>(*)>(_a[2]))); break;
        case 40: _t->setState((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 36:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 39:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        }
    }
}

const QMetaObject ClassCombinerUserInterface::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ClassCombinerUserInterface.data,
      qt_meta_data_ClassCombinerUserInterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClassCombinerUserInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClassCombinerUserInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClassCombinerUserInterface.stringdata0))
        return static_cast<void*>(const_cast< ClassCombinerUserInterface*>(this));
    return QWidget::qt_metacast(_clname);
}

int ClassCombinerUserInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
