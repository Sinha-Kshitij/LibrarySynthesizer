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
#include <QTextEdit>

// Dialog Box that allows for the modification of the definitions of headers and sources
class HeaderAndSourceTypesDialog : public QDialog
{
    Q_OBJECT

    public:
        // Constructor
        HeaderAndSourceTypesDialog();

    public slots:
        // Approriately opens and closes and transfers data to the main class
        void hideOrOpen(bool ignore);
        // Modifies vectors to the current definitions of headers and sources
        void open(QVector<QString> headerTypes, QVector<QString> sourceTypes);

    private:
        // Elements necessary to create the UI
        QGridLayout *layout;

        QListWidget *headerTypesWidget;
        QPushButton *addHeaderTypes;
        QPushButton *removeHeaderTypes;

        QListWidget *sourceTypesWidget;
        QPushButton *addSourceTypes;
        QPushButton *removeSourceType;

        QPushButton *accept;
        QPushButton *reject;
        bool emitInformation;
        bool status;

        // Overrides close event to be in conjunction with function "hideOrOpen"
        void closeEvent(QCloseEvent *ev);

    private slots:
        // Add header/source using a dialog box
        void addHeaderTypesFunction(bool ignore);
        void addSourceTypesFunction(bool ignore);
        // Remove the currently selected approriate header/source definition
        void removeHeaderTypesFunction(bool ignore);
        void removeSourceTypesFunction(bool ignore);
        // Ensure that changes made to header/source definitions are not transmitted
        void rejectFunction(bool ignore);

    signals:
        // Update the definition types to the main program
        void updateTypes(QVector<QString> headerTypes, QVector<QString> sourceTypes);
};

// Dialog box that is used to display files that are self dependent
// Automatically pops up if error during synthesis is detected.
class SelfDependentDisplayDialog : public QDialog
{
    Q_OBJECT
    
    public:
        SelfDependentDisplayDialog();
        bool visible;

    private:
        QGridLayout *layout;
        QListWidget *selfDependentList;
        QComboBox *formTypeCombo;

        QPushButton *okButton;
        QPushButton *checkButton;

    signals:
        void checkForSelfDependence();

    public slots:
        void showOrHide(bool ignore);
        QString shortName(QString text);
        void closeEvent(QCloseEvent *ev);
        void loadSelfDependentValues(QVector<QString> string);

    private slots:
        void formTypeFunction(QString text);
        void checkFilesForSelfDependence(bool ignore);
};

// Dialog Box that details method used to worry
class SynthesisDiagnostics : public QDialog
{
    Q_OBJECT

    public:
        SynthesisDiagnostics();


    private:
        QGridLayout *layout;
        bool visible;

        // GUI Elements
        QLineEdit *fileInQuestion;
        QTextEdit *dependencyContainer;
        QListWidget *simplifiedDependencyContainer;
        QTextEdit *informationContainer;

    public slots:
        void showOrHide();
        //void synthesisUpdate();

    private slots:


    signals:
        void demandInformationTransfer();

};

// Combines the UI and the main functions of the synthesizer
class ClassCombinerUserInterface : public QWidget
{
    Q_OBJECT

    public:
        // Instantiate the user interface, connect the functions to the UI and ensure initial state is correct
        ClassCombinerUserInterface();

    private slots:
        // Part 1 Functions - Determine Source Materials
        void addFile(bool ignore); // Add the file to be analyzed and synthesized. Only addresses the UI.
        void addFile(QString file); // Adds the file to the internal data structure taking into account degeneracy of the data
        void addFileUI(QString file); // Adds the file purely to the UI accounting for current file type and according to the current display name type
        void removeFile(bool ignore); // Remvoe the file. Only addresses UI
        void addFolder(bool ignore); // Analyze the folder (potentially recursively) for files relevant for synthesis. Only addresses th UI.
        bool addFolder(QString folderToAdd); // Add the folder to be analyzed with files relevant for synthesis. Addresses the internal data structure
        void addFolderUI(QString folder); // Focuses on the UI associated with the list widget, approriate display type, and sorting.
        void removeFolder(bool ignore); // Remove the folder from the UI and internal data structure
        bool checkForDegeneracy(QString file); // Checks for repetition of data structure within the internal structure
        bool checkForFolderDegeneracy(QString folder); // Checks for repetition of data within the internal folder structure
        bool checkForHeaderType(QString text); // Checks whether the file is of type header in accordance with definitions
        bool checkForSourceType(QString text); // Checks whether the file is of type sources in accordance with definitions

        void recursiveSearch(QString sourceFolder); // Searches recursively through the folders looking for headers and sources
        void findAllHeadersAndSourcesLocally(QString folderNameInput); // Finds the headers and sources in the local directory
        QString shortName(QString text); // Processes the full name of a file location, resulting in the local directory name of the file

        void filterChanged(QString text); // Changes the filter to either display the header and source types
        void sortFolders(bool ignore); // Sorts the folders alphabetically
        void sortFiles(bool ignore); // Sorts the current files displayed alphabetically
        void folderNameDisplay(QString text); // Modifies the display type of the folders
        void filesNameDisplay(QString text); // Modifies the display type of the files

        // Part 2 Functions - Select Output Files
        void selectHeaderFile(bool ignore); // Selects the header file for output
        void selectSourceFile(bool ignore); // Selects the source file for output

        // Part 3 Functions - File information Display
        void fileTypeSelectorFunction(QString text); // Lists the file type whose dependencies are to be inspected
        void fileSelectorFunction(QString text); // Lists the dependencies of the current files
        void removeDependencyFunction(bool ignore); // Removes the dependency currently selected

        // Part 4 Functions
        void dependencyDisplay(QString text); // Used by "dependencyListType"  to display the dependencies of either the current file, or according to solution type
        void dependencySolutionList(QString text); // Lists the dependencies and solutions
        void assignDependency(bool ignore); // Assigns the current dependency proposed solution as the solution for current dependency
        void addDependencyFunction(bool ignore); // Adds a solution beyond the current scope of potential solutions as the dependency solution for the dependency in question!
        void assignedDependencyFunction(QString text); // Displays the full form of the text
        void removeSolutionsFunction(bool ignore); // Clears the list of potential solutions for the given dependency

        // Ensures all structures are in place
        // Combines UI from 1, 2, 3, 4
        // Ensures the internal structure is coherent when files are added. Also analyzes files for dependencies and source information
        // And adds unique dependencies as approriate
        void ensureStructuralCoherence();
        void ensureStructuralCoherence(int indexOfRemoval); // Ensures the internal structure is coherent when files are removed
        // Analyzes file, seeking out all include statements, the relevant information withint the file
        // and attempts to find all other dependencies the file has.
        // Analyzes the files for dependencies, source and source information.
        void analyzeFile(QString fileInput, int indexWithinStructure, QVector<QString> &dependencyInformationOriginal);
        QString analyzeIncludeStatement(QString text); // Analyzes include statement

        // Part 5 Functions - Structure Display


        // Part 6 Functions - Analyze and Combine
        void analyzeAll(bool ignore); // Analyzes all files for dependencies
        // Finds the solution of the dependencies from the internal file set
        void findDependenciesSolutions(int indexOfDependency);
        // Use a rating of similarity to determine what the solutions are
        void similarityRating(QString dependency, QString potentialSolution, int &rating, bool &validRating);
        // Synthesize the files by getting structure
        void synthesize(bool ignore); // Combines all the files in accordance with dependency structure
        // Removes all self-dependencies. Occurs post analysis and prior to synthesis, checking for dependencies whose solution points to the file itself!
        // Displays a dialog box containing the dependencies that point to themselves.
        bool checkForSelfDependencies();
        // Add the unique dependencies not already added
        void uniquelyAddDependencies(QVector<QString> &listOfAllDependenciesLocal,
                                     QVector<QString> &temporaryUniqueDependencies, QVector<QString> dependencyData);
        // Add and analyze the file and all its dependencies
        // Does not add main functions
        void addAndAnalyzeFile(QString fileToConsider,  QVector<QVector<QString>> &listOfAllSources,
                               QVector<QString> &listOfAllDependencies, QVector<QString> &temporaryInformationOfFiles,
                               QVector<QString> &temporaryUniqueDependencies, QVector<QString> &solvedDependencies, QVector<QString> &localChain);
        // Add external file not already analyzed
        void extractAndAddFile(QString fileInput, QVector<QString> &temporaryInformationOfFiles,
                               QVector<QString> &temporaryUniqueDependencies, QVector<QString> &listOfAllDependencies,
                               QVector<QVector<QString> > &listOfAllSources);
        // Add data from file not contained within structure
        void extractInformationFromFile(QString fileInput, QVector<QString> &dependencies, QVector<QString> &sourceExcludingMain, QString &mainFunction);
        // Get original form
        QString extractDependencyOriginalForm(QString result);


        // UI stuff
        void openDialog(bool ignore); // Opens the dialog for manipulation of header and source types definition
        QStringList convertVectorToList(QVector<QString> dataToBeConverted); // Converts data from QVector to QStringList form
        void themeFunction(bool ignore); // Opens the dialog box for theme definition
        void refreshFunction(bool ignore); // Refreshed the function, setting state to initial state
        void updateTypes(QVector<QString> headersTypesInput, QVector<QString> sourceTypesInput); // updates the data according to header/source type definition
        void setState(int state); // Sets the state of the UI approriately

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
        QComboBox *dependencySelected;
        QPushButton *removeDependencyButton;

        // Part 4 - Dependency Assignment
        QGroupBox *dependencyAssignmentBox;
        QGridLayout *dependencyAssignmentLayout;
        QComboBox *dependencyListType; // DependencyDisplay
        QComboBox *listOfDependencies; // DependencySolutionList
        QComboBox *assignedDependencySolutions; // Controlled by DependencySolutionList, or assignDependencyButton, or addDependencyButton
        QPushButton *assignDependencyButton; // Switches the current item at assignedDependency to top of assigned dependency
        QPushButton *addDependencySolutionButton; // Adds to assignedDependency
        QLineEdit *assignedDependencySolutionLineEdit; // Displays completely the solution list
        QPushButton *removeDependencySolutionsButton; // Removes all proposed solutions

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
        QPushButton *selfDependendentDisplayButton;
        HeaderAndSourceTypesDialog *headerAndSourceTypesDialog;
        SelfDependentDisplayDialog *selfDependentDisplayDialog;

        // Overall layout
        QGridLayout *classCombinerUserInterfaceLayout;
        QLineEdit *statusBar;

        // Private variables
        // The following 5 internal structures are coherent
        QVector<QString> informationOfFiles; // Contains the absolute file location
        QVector<QVector<QString>> dependenciesOfFiles; // Contains the dependency of a file
        QVector<QVector<bool>> stateOfDependenciesOfFiles; // Contains whether the dependencies of the files are resolved
        QVector<QVector<QString>> informationContainedWithinFiles; // Contains the source information of files independent of dependencies

        // The following 2 internal structure are coherent. One contains the dependencies, the other the solution
        QVector<QString> uniqueDependencies; // Contains the list of unique dependencies
        QVector<QString> dependencyOriginalForm;
        QVector<QVector<QString>> dependencyFillingList; // Contains the list of potential solutions for a given dependency. Aligned with uniqueDependency

        // The following internal structures contain the inter-dependencies of the files
        QVector<QVector<QString>> interpendenciesPointer;

        // The following internal structures contain the headers, sources, and folder types. These are not related directly to synthesis of the data.
        QVector<QString> informationOfHeaderFiles; // Contains the absolute file location of all headers
        QVector<QString> informationOfSourceFiles; // Contains the sbsolute file location of all sources
        QVector<QString> informationOfFolders; // Contains the location of all folders used

        // The following 2 contain the definitions of headers and sources
        QVector<QString> headerTypes; // Contains the type of definitions of header types
        QVector<QString> sourceTypes; // Contains the type of definitions of source types

        // Files that presumably have a well defined entry point
        QVector<QVector<QString>> mainFilesAndDefinition;

        // State
        int stateVariable;
        int idealState;
};

#endif // CLASSCOMBINERUSERINTERFACE

