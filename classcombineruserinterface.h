#ifndef CLASSCOMBINERUSERINTERFACE
#define CLASSCOMBINERUSERINTERFACE

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QVector>
#include <QString>
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
#include <QIcon>
#include <QPixmap>
#include <QImage>
#include <QStringList>
#include <QFileInfoList>
#include <iostream>
#include <QComboBox>
#include <QCheckBox>
#include <QFile>
#include <QTableWidget>
#include <QTableView>
#include <QDialog>
#include <QHeaderView>
#include <QInputDialog>
#include <QStatusBar>

class HeaderAndSourceTypesDialog : public QDialog
{
    Q_OBJECT

    public:
        HeaderAndSourceTypesDialog();

    public slots:
        void hideOrOpen(bool ignore);
        void open(QVector<QString> headerTypes, QVector<QString> sourceTypes);

    private:
        QGridLayout *layout;

        QListWidget *headerTypesWidget;
        QPushButton *addHeaderTypes;
        QPushButton *removeHeaderTypes;

        QListWidget *sourceTypesWidget;
        QPushButton *addSourceTypes;
        QPushButton *removeSourceType;

        QPushButton *accept;
        bool status;

        void closeEvent(QCloseEvent *ev);

    private slots:
        void addHeaderTypesFunction(bool ignore);
        void addSourceTypesFunction(bool ignore);
        void removeHeaderTypesFunction(bool ignore);
        void removeSourceTypesFunction(bool ignore);

    signals:
        void updateTypes(QVector<QString> headerTypes, QVector<QString> sourceTypes);

};

class ClassCombinerUserInterface : public QWidget
{
    Q_OBJECT

    public:
        ClassCombinerUserInterface();

    private slots:
        // Part 1 Functions - Determine Source Materials
        void addFile(bool ignore);
        void addFile(QString file);
        void addFileUI(QString file);
        void removeFile(bool ignore);
        void addFolder(bool ignore);
        bool addFolder(QString folderToAdd);
        void addFolderUI(QString folder);
        void removeFolder(bool ignore);
        bool checkForDegeneracy(QString file);
        bool checkForFolderDegeneracy(QString folder);
        bool checkForHeaderType(QString text);
        bool checkForSourceType(QString text);

        void recursiveSearch(QString sourceFolder);
        void findAllHeadersAndSourcesLocally(QString folderNameInput);
        QString shortName(QString text);

        void filterChanged(QString text);
        void sortFolders(bool ignore);
        void sortFiles(bool ignore);
        void folderNameDisplay(QString text);
        void filesNameDisplay(QString text);

        // Part 2 Functions - Select Output Files
        void selectHeaderFile(bool ignore);
        void selectSourceFile(bool ignore);

        // Part 3 Functions - File information Display
        void fileTypeSelectorFunction(QString text); // ?
        void fileSelectorFunction(QString text); // ?

        // Part 4 Functions
        void dependencyDisplay(QString text); // Used by "dependencyListType"
        void dependencySolutionList(QString text); // Lists the dependencies as desired
        void assignDependency(bool ignore); // Switches the structure of the items
        void addDependencyFunction(bool ignore);

        // Ensures all structures are in place
        // Combines UI from 1, 2, 3, 4
        void ensureStructuralCoherence();
        void ensureStructuralCoherence(int indexOfRemoval);


        // Part 5 Functions - Structure Display


        // Part 6 Functions - Analyze and Combine
        void analyzeAll(bool ignore);
        void synthesize(bool ignore);
        // Analyzes file, seeking out all include statements, the relevant information withint the file
        // and attempts to find all other dependencies the file has
        void analyzeFile(QString fileInput, int indexWithinStructure);
        // Analyzes include statement
        QString analyzeIncludeStatement(QString text);
        // Finds whether the file dependencies are local
        void findFileDependencies(int index);

        // UI stuff
        void openDialog(bool ignore);
        void themeFunction(bool ignore);
        void refreshFunction(bool ignore);
        void updateTypes(QVector<QString> headersTypesInput, QVector<QString> sourceTypesInput);
        void setState(int state);

    private:
        // Part 1 - Folder and files adder
        QGroupBox *folderAndFileLocationsBox;
        QGridLayout *folderAndFileLocationsBoxLayout;

        QListWidget *foldersToCombine;
        QPushButton *folderAdderButton;
        QPushButton *folderRemoverButton;
        QCheckBox *activateRecursiveSearch;
        QPushButton *sortFolderButton;
        QComboBox *folderNameForm;

        QListWidget *filesToCombine;
        QPushButton *fileAdderButton;
        QPushButton *fileRemoverButton;
        QComboBox *fileTypeFilter;
        QPushButton *sortFilesButton;
        QComboBox *filesNameForm;

        // Part 2 - Output Part
        QGroupBox *outputFileBox;
        QLineEdit *outputHeaderFile;
        QPushButton *saveHeaderFileButton;
        QLineEdit *outputSourceFile;
        QPushButton *saveSourceFileButton;
        QGridLayout *outputFileBoxLayout;

        // Part 3 - Information Display
        QGroupBox *fileInformationDisplayBox;
        QComboBox *fileTypeSelector;
        QComboBox *fileSelector;
        QTableWidget *informationDisplayTable;
        QGridLayout *fileInformationDisplayLayout;

        // Part 4 - Dependency Assignment
        QGroupBox *dependencyAssignmentBox;
        QGridLayout *dependencyAssignmentLayout;
        QComboBox *dependencyListType; // DependencyDisplay
        QComboBox *listOfDependencies; // DependencySolutionList
        QComboBox *assignedDependency; // Controlled by DependencySolutionList, or assignDependencyButton, or addDependencyButton
        QPushButton *assignDependencyButton; // Switches the current item at assignedDependency to top of assigned dependency
        QPushButton *addDependencyButton; // Adds to assignedDependency

        // Part 5 - Structural Decomposer
        QGroupBox *structuralDecomposerBox;
        QGridLayout *structuralBoxLayout;
        QPushButton *refreshButton;

        // Part 6 - Analyze And Combine
        QGroupBox *primaryBox;
        QGridLayout *primaryBoxLayout;
        QPushButton *analyzeButton;
        QPushButton *synthesizeButton;
        QPushButton *settingsButton;
        QPushButton *themeButton;
        HeaderAndSourceTypesDialog *headerAndSourceTypesDialog;

        // Overall layout
        QGridLayout *classCombinerUserInterfaceLayout;
        QLineEdit *statusBar;

        // Private variables
        QVector<QString> informationOfFiles; // Contains the absolute file location
        QVector<QString> informationOfHeaderFiles; // Contains the absolute file location of all headers
        QVector<QString> informationOfSourceFiles; // Contains the sbsolute file location of all sources
        QVector<QString> informationOfFolders; // Contains the location of all folders used

        QVector<QVector<QString>> dependenciesOfFiles; // Contains the dependency of a file
        QVector<QVector<bool>> stateOfDependenciesOfFiles;
        QVector<QString> informationContainedWithinFiles;
        QVector<int> structureWeight;

        QVector<QString> uniqueDependencies;
        QVector<QVector<QString>> dependencyFillingList;

        QVector<QString> headerTypes;
        QVector<QString> sourceTypes;

        // State
        int stateVariable;
};

#endif // CLASSCOMBINERUSERINTERFACE

