#include "classcombineruserinterface.h"

ClassCombinerUserInterface::ClassCombinerUserInterface()
{
    classCombinerUserInterfaceLayout = new QGridLayout;

    // ***** Part 1 - Folder And File Location *****
    folderAndFileLocationsBox = new QGroupBox;
    folderAndFileLocationsBox->setTitle("Accumulation Sources");
    folderAndFileLocationsBoxLayout = new QGridLayout;

    // Folders
    foldersToCombine = new QListWidget;
    folderAdderButton = new QPushButton;
    connect(folderAdderButton, SIGNAL(clicked(bool)), this, SLOT(addFolder(bool)));
    folderAdderButton->setIcon(QIcon(":/images/Images/Add.ico"));
    folderRemoverButton = new QPushButton;
    connect(folderRemoverButton, SIGNAL(clicked(bool)), this, SLOT(removeFolder(bool)));
    folderRemoverButton->setIcon(QIcon(":/images/Images/Subtract.png"));
    activateRecursiveSearch = new QCheckBox;
    activateRecursiveSearch->setChecked(true);
    sortFolderButton = new QPushButton;
    connect(sortFolderButton, SIGNAL(clicked(bool)), this, SLOT(sortFolders(bool)));
    sortFolderButton->setIcon(QIcon(":/images/Images/AZ_Sort.ico"));
    folderNameForm = new QComboBox;
    folderNameForm->addItem("Long");
    folderNameForm->addItem("Short");
    connect(folderNameForm, SIGNAL(currentTextChanged(QString)), this, SLOT(folderNameDisplay(QString)));
    connect(folderNameForm, SIGNAL(currentTextChanged(QString)), this, SLOT(folderNameDisplay(QString)));
    folderAndFileLocationsBoxLayout->addWidget(new QLabel("Folders"), 0, 0, 1, 1);
    folderAndFileLocationsBoxLayout->addWidget(folderRemoverButton, 0, 2, 1, 1);
    folderAndFileLocationsBoxLayout->addWidget(folderAdderButton, 0, 3, 1, 1);
    folderAndFileLocationsBoxLayout->addWidget(new QLabel("Search subdirectories"), 1, 0, 1, 3);
    folderAndFileLocationsBoxLayout->addWidget(activateRecursiveSearch, 1, 3, 1, 1, Qt::AlignRight);
    folderAndFileLocationsBoxLayout->addWidget(foldersToCombine, 2, 0, 4, 4);
    //folderAndFileLocationsBoxLayout->addWidget(new QLabel("Sort"), 6, 0, 1, 1, Qt::AlignLeft);
    folderAndFileLocationsBoxLayout->addWidget(sortFolderButton, 6, 0, 1 ,1, Qt::AlignLeft);
    folderAndFileLocationsBoxLayout->addWidget(new QLabel("Display Form"), 6, 2, 1, 1), Qt::AlignRight;
    folderAndFileLocationsBoxLayout->addWidget(folderNameForm, 6, 3, 1, 1, Qt::AlignLeft);
    
    // Files
    filesToCombine = new QListWidget;
    fileAdderButton = new QPushButton;
    connect(fileAdderButton, SIGNAL(clicked(bool)), this, SLOT(addFile(bool)));
    fileAdderButton->setIcon(QIcon(":/images/Images/Add.ico"));
    fileRemoverButton = new QPushButton;
    connect(fileRemoverButton, SIGNAL(clicked(bool)), this, SLOT(removeFile(bool)));
    fileRemoverButton->setIcon(QIcon(":/images/Images/Subtract.png"));
    fileTypeFilter = new QComboBox;
    fileTypeFilter->addItem("Headers");
    fileTypeFilter->addItem("Source Files");
    connect(fileTypeFilter, SIGNAL(currentIndexChanged(QString)), this, SLOT(filterChanged(QString)));
    sortFilesButton = new QPushButton;
    connect(sortFilesButton, SIGNAL(clicked(bool)), this, SLOT(sortFiles(bool)));
    sortFilesButton->setIcon(QIcon(":/images/Images/AZ_Sort.ico"));
    filesNameForm = new QComboBox;
    filesNameForm->addItem("Long");
    filesNameForm->addItem("Short");
    connect(filesNameForm, SIGNAL(currentTextChanged(QString)), this, SLOT(filesNameDisplay(QString)));
    folderAndFileLocationsBoxLayout->addWidget(new QLabel("Files"), 0, 5, 1, 1);
    folderAndFileLocationsBoxLayout->addWidget(fileTypeFilter, 0,6 ,1, 1);
    folderAndFileLocationsBoxLayout->addWidget(fileRemoverButton, 0, 7, 1, 1);
    folderAndFileLocationsBoxLayout->addWidget(fileAdderButton, 0, 8, 1, 1);
    folderAndFileLocationsBoxLayout->addWidget(filesToCombine, 1, 5, 5, 4);
    //folderAndFileLocationsBoxLayout->addWidget(new QLabel("Sort"), 6, 5, 1, 1, Qt::AlignLeft);
    folderAndFileLocationsBoxLayout->addWidget(sortFilesButton, 6, 5, 1 ,1, Qt::AlignLeft);
    folderAndFileLocationsBoxLayout->addWidget(new QLabel("Display Form"), 6, 7, 1, 1, Qt::AlignRight);
    folderAndFileLocationsBoxLayout->addWidget(filesNameForm, 6, 8, 1, 1, Qt::AlignLeft);
    folderAndFileLocationsBox->setLayout(folderAndFileLocationsBoxLayout);

    // ***** Part 2 - Resulting output box *****
    outputFileBox = new QGroupBox;
    outputFileBox->setTitle("Resulting Files");
    outputFileBoxLayout = new QGridLayout;
    outputHeaderFile = new QLineEdit;
    outputHeaderFile->setReadOnly(true);
    outputSourceFile = new QLineEdit;
    outputSourceFile->setReadOnly(true);
    saveHeaderFileButton = new QPushButton;
    saveHeaderFileButton->setIcon(QIcon(":/images/Images/folderIcon.ico"));
    connect(saveHeaderFileButton, SIGNAL(clicked(bool)), this, SLOT(selectHeaderFile(bool)));
    saveSourceFileButton = new QPushButton;
    saveSourceFileButton->setIcon(QIcon(":/images/Images/folderIcon.ico"));
    connect(saveSourceFileButton, SIGNAL(clicked(bool)), this, SLOT(selectSourceFile(bool)));
    outputFileBoxLayout->addWidget(new QLabel("Header File"), 0, 0, 1, 1);
    outputFileBoxLayout->addWidget(new QLabel("Source File"), 1, 0, 1, 1);
    outputFileBoxLayout->addWidget(outputHeaderFile, 0, 1, 1, 3);
    outputFileBoxLayout->addWidget(outputSourceFile, 1, 1, 1, 3);
    outputFileBoxLayout->addWidget(saveHeaderFileButton, 0, 4, 1, 1);
    outputFileBoxLayout->addWidget(saveSourceFileButton, 1, 4, 1, 1);
    outputFileBox->setLayout(outputFileBoxLayout);

    // ***** Part 3 - Information Display *****
    fileInformationDisplayBox = new QGroupBox;
    fileInformationDisplayLayout = new QGridLayout;
    fileInformationDisplayBox->setTitle("Information Display");
    fileTypeSelector = new QComboBox;
    fileTypeSelector->addItem("Headers");
    fileTypeSelector->addItem("Sources");
    connect(fileTypeSelector, SIGNAL(currentTextChanged(QString)), this, SLOT(fileTypeSelectorFunction(QString)));
    fileSelector = new QComboBox;
    connect(fileSelector, SIGNAL(currentTextChanged(QString)), this, SLOT(fileSelectorFunction(QString)));
    informationDisplayTable = new QTableWidget;
    informationDisplayTable->verticalHeader()->setVisible(false);
    informationDisplayTable->horizontalHeader()->setVisible(false);
    fileInformationDisplayLayout->addWidget(new QLabel("File Type"), 0, 0, 1, 1);
    fileInformationDisplayLayout->addWidget(fileTypeSelector, 0, 1, 1, 1);
    fileInformationDisplayLayout->addWidget(new QLabel("File"), 1, 0, 1, 1);
    fileInformationDisplayLayout->addWidget(fileSelector, 1, 1, 1, 1);
    fileInformationDisplayLayout->addWidget(informationDisplayTable, 2, 0, 5, 2);
    fileInformationDisplayBox->setLayout(fileInformationDisplayLayout);

    // ***** Part 4 - Dependency Assignment *****
    dependencyAssignmentBox = new QGroupBox;
    dependencyAssignmentBox->setTitle("Dependency Assignment");
    dependencyAssignmentLayout = new QGridLayout;
    dependencyListType = new QComboBox;
    dependencyListType->addItem("Current File");
    dependencyListType->addItem("All");
    dependencyListType->addItem("All Unassigned");
    dependencyListType->addItem("All Assigned");
    connect(dependencyListType, SIGNAL(currentTextChanged(QString)), this, SLOT(dependencyDisplay(QString)));
    listOfDependencies = new QComboBox;
    connect(listOfDependencies, SIGNAL(currentTextChanged(QString)), this, SLOT(dependencySolutionList(QString)));
    assignDependencyButton = new QPushButton;
    assignDependencyButton->setText("Assign");
    connect(assignDependencyButton, SIGNAL(clicked(bool)), this, SLOT(assignDependency(bool)));
    addDependencyButton = new QPushButton;
    addDependencyButton->setIcon(QIcon(":/images/Images/Add.ico"));
    connect(addDependencyButton, SIGNAL(clicked(bool)), this, SLOT(addDependencyFunction(bool)));
    assignedDependency = new QComboBox;
    dependencyAssignmentLayout->addWidget(new QLabel("List Type"), 0, 0, 1, 1);
    dependencyAssignmentLayout->addWidget(dependencyListType, 0, 1, 1, 2);
    dependencyAssignmentLayout->addWidget(new QLabel("Dependency"), 1, 0, 1, 1);
    dependencyAssignmentLayout->addWidget(listOfDependencies, 1, 1, 1, 2);
    dependencyAssignmentLayout->addWidget(assignedDependency, 2, 0, 1, 1);
    dependencyAssignmentLayout->addWidget(assignDependencyButton, 2, 1, 1, 1);
    dependencyAssignmentLayout->addWidget(addDependencyButton, 2, 2, 1, 1);
    dependencyAssignmentBox->setLayout(dependencyAssignmentLayout);

    // ***** Part 5 - The structure of the system can be viewed *****
    structuralDecomposerBox = new QGroupBox;
    structuralDecomposerBox->setTitle("Structure");
    structuralBoxLayout = new QGridLayout;

    structuralDecomposerBox->setLayout(structuralBoxLayout);


    // ***** Part 6 - Analyze And Combine *****
    primaryBox = new QGroupBox;
    primaryBox->setTitle("Analyze And Synthesize");
    primaryBoxLayout = new QGridLayout;
    headerAndSourceTypesDialog = new HeaderAndSourceTypesDialog();
    connect(headerAndSourceTypesDialog, SIGNAL(updateTypes(QVector<QString>,QVector<QString>)), this, SLOT(updateTypes(QVector<QString>,QVector<QString>)));
    analyzeButton = new QPushButton;
    connect(analyzeButton, SIGNAL(clicked(bool)), this, SLOT(analyzeAll(bool)));
    analyzeButton->setIcon(QIcon(":/images/Images/examine.png"));
    synthesizeButton = new QPushButton;
    connect(synthesizeButton, SIGNAL(clicked(bool)), this, SLOT(synthesize(bool)));
    synthesizeButton->setIcon(QIcon(":/images/Images/combine.ico"));
    themeButton = new QPushButton;
    themeButton->setIcon(QIcon(":/images/Images/palette.png"));
    connect(themeButton, SIGNAL(clicked(bool)), this, SLOT(themeFunction(bool)));
    settingsButton = new QPushButton;
    settingsButton->setIcon(QIcon(":/images/Images/Green-gear.png"));
    connect(settingsButton, SIGNAL(clicked(bool)), this, SLOT(openDialog(bool)));
    primaryBoxLayout->addWidget(themeButton, 0, 0, 1, 1);
    primaryBoxLayout->addWidget(settingsButton, 0, 1, 1, 1);
    primaryBoxLayout->addWidget(analyzeButton, 0, 2, 1, 1);
    primaryBoxLayout->addWidget(synthesizeButton, 0, 3, 1, 1);
    primaryBox->setLayout(primaryBoxLayout);

    // ***** Overall - Setup the overall UI *****
    statusBar = new QLineEdit;
    statusBar->setReadOnly(true);
    refreshButton =  new QPushButton;
    connect(refreshButton, SIGNAL(clicked(bool)), this, SLOT(refreshFunction(bool)));
    refreshButton->setIcon(QIcon(":/images/Images/RefreshImage.png"));
    classCombinerUserInterfaceLayout->addWidget(folderAndFileLocationsBox, 0, 0, 5, 5);
    classCombinerUserInterfaceLayout->addWidget(outputFileBox, 5, 0, 1, 3);
    classCombinerUserInterfaceLayout->addWidget(primaryBox, 5, 3, 1, 2);
    classCombinerUserInterfaceLayout->addWidget(fileInformationDisplayBox, 0, 5, 3, 3);
    classCombinerUserInterfaceLayout->addWidget(dependencyAssignmentBox, 3, 5, 1, 3);
    classCombinerUserInterfaceLayout->addWidget(structuralDecomposerBox, 4, 5, 2, 3);
    classCombinerUserInterfaceLayout->addWidget(statusBar, 6, 0, 1, 7);
    classCombinerUserInterfaceLayout->addWidget(refreshButton, 6, 7, 1, 1);
    this->setLayout(classCombinerUserInterfaceLayout);

    // Initialize the standard definitions
    headerTypes << ".h" << ".hxx";
    sourceTypes << ".cpp" << ".cxx";

    // Initialize the program
    stateVariable = -1;
    setState(0);
}

// ***** Part 1 Functions
void ClassCombinerUserInterface::addFile(bool ignore)
{
    ignore;
    int index = 0;
    QString filter = "Headers (";
    for(index = 0; index < headerTypes.length(); index++)
    {
        filter += "*" + headerTypes.at(index);
        if(index < headerTypes.length() - 1)
        {
                  filter += " ";
        }
    }

    filter += ");; Sources (";
    for(index = 0; index < sourceTypes.length(); index++)
    {
        filter += "*" + sourceTypes.at(index);
        if(index < sourceTypes.length() - 1)
        {
                  filter += " ";
        }
    }
    filter += ");; All Files (*.*)";

    QStringList filesToAdd = QFileDialog::getOpenFileNames(this, tr("Open Header/Source Files"), "/home", filter);
    for(index = 0; index < filesToAdd.length(); index++)
    {
        addFile(filesToAdd.at(index));
    }
}
void ClassCombinerUserInterface::addFile(QString file)
{
    if(checkForDegeneracy(file))
    {
        if(checkForHeaderType(file) || checkForSourceType(file))
        {
            informationOfFiles.append(file);

            if(checkForHeaderType(file))
            {
                informationOfHeaderFiles.append(file);
            }
            else if(checkForSourceType(file))
            {
                informationOfSourceFiles.append(file);
            }

            ensureStructuralCoherence();
            addFileUI(file);

            setState(1);
        }
    }
}
void ClassCombinerUserInterface::addFileUI(QString file)
{
    if(checkForHeaderType(file) && fileTypeFilter->currentText() == "Headers")
    {
        if(filesNameForm->currentText() == "Long")
        {
            filesToCombine->addItem(file);
        }
        else if(filesNameForm->currentText() == "Short")
        {
            filesToCombine->addItem(shortName(file));
        }
    }
    else if(checkForSourceType(file) && fileTypeFilter->currentText() == "Source Files")
    {
        if(filesNameForm->currentText() == "Long")
        {
            filesToCombine->addItem(file);
        }
        else if(filesNameForm->currentText() == "Short")
        {
            filesToCombine->addItem(shortName(file));
        }
    }
}
void ClassCombinerUserInterface::removeFile(bool ignore)
{
    ignore;
    int currentlySelected = filesToCombine->currentRow();
    QString textRemoved = "";
    if(currentlySelected >= 0 && currentlySelected < filesToCombine->count())
    {
        textRemoved = filesToCombine->item(currentlySelected)->text();
    }

    // Find the complete matching string if neccessary
    if(filesNameForm->currentText() == "Short")
    {
        for(currentlySelected = 0; currentlySelected < informationOfFiles.length(); currentlySelected++)
        {
            if(informationOfFiles.at(currentlySelected).endsWith(textRemoved))
            {
                textRemoved = informationOfFiles.at(currentlySelected);
                break;
            }
        }
    }
    else
    {
        currentlySelected = informationOfFiles.indexOf(textRemoved);
    }

    informationOfFiles.remove(currentlySelected);
    ensureStructuralCoherence(currentlySelected);

    if(checkForHeaderType(textRemoved))
    {
        informationOfHeaderFiles.remove(informationOfHeaderFiles.indexOf(textRemoved));
    }
    else if(checkForSourceType(textRemoved))
    {
        informationOfSourceFiles.remove(informationOfSourceFiles.indexOf(textRemoved));
    }

    if(informationOfFiles.length() == 0)
    {
        setState(0);
    }
    else
    {
        setState(1);
    }
}
void ClassCombinerUserInterface::addFolder(bool ignore)
{
    ignore;
    QString folderToAdd = QFileDialog::getExistingDirectory(this, tr("Open Directory for Header/Source Files"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if(checkForFolderDegeneracy(folderToAdd))
    {
        if(activateRecursiveSearch->isChecked())
        {
            recursiveSearch(folderToAdd);
        }
        else
        {
            findAllHeadersAndSourcesLocally(folderToAdd);
        }
    }
}
bool ClassCombinerUserInterface::addFolder(QString folderToAdd)
{
    bool result = false;
    if(QDir(folderToAdd).isReadable() && !folderToAdd.contains(".."))
    {
        if(checkForFolderDegeneracy(folderToAdd))
        {
            if(folderNameForm->currentText() == "Long")
            {
                foldersToCombine->addItem(folderToAdd);
            }
            else if(folderNameForm->currentText() == "Short")
            {
                foldersToCombine->addItem(shortName(folderToAdd));
            }

            informationOfFolders.append(folderToAdd);
            result = true;
        }
    }
    return result;
}
void ClassCombinerUserInterface::addFolderUI(QString folder)
{
    if(folderNameForm->currentText() == "Long")
    {
        foldersToCombine->addItem(folder);
    }
    else if(folderNameForm->currentText() == "Short")
    {
        foldersToCombine->addItem(shortName(folder));
    }
}
void ClassCombinerUserInterface::removeFolder(bool ignore)
{
    ignore;
    int currentlySelected = foldersToCombine->currentRow();
    QString textRemoved = "";
    if(currentlySelected >= 0 && currentlySelected < foldersToCombine->count())
    {
        textRemoved = foldersToCombine->takeItem(currentlySelected)->text();
    }

}
bool ClassCombinerUserInterface::checkForDegeneracy(QString file)
{
    bool result = true;
    if(informationOfFiles.contains(file))
    {
        result = false;
    }
    return result;
}
bool ClassCombinerUserInterface::checkForFolderDegeneracy(QString folder)
{
    bool result = true;
    if(informationOfFolders.contains(folder))
    {
        result = false;
    }
    return result;
}
bool ClassCombinerUserInterface::checkForHeaderType(QString text)
{
    bool result = false;
    int index = 0;
    for(index = 0; index < headerTypes.length(); index++)
    {
        if(text.endsWith(headerTypes.at(index), Qt::CaseInsensitive))
        {
            result = true;
            break;
        }
    }

    return result;
}
bool ClassCombinerUserInterface::checkForSourceType(QString text)
{
    bool result = false;
    int index = 0;
    for(index = 0; index < sourceTypes.length(); index++)
    {
        if(text.endsWith(sourceTypes.at(index), Qt::CaseInsensitive))
        {
            result = true;
            break;
        }
    }

    return result;
}
void ClassCombinerUserInterface::folderNameDisplay(QString text)
{
    text;

    foldersToCombine->clear();
    int index = 0;
    for(index = 0; index < informationOfFolders.length(); index++)
    {
          addFolderUI(informationOfFolders.at(index));
    }
}
void ClassCombinerUserInterface::filesNameDisplay(QString text)
{
    text;

    filesToCombine->clear();
    int index = 0;
    if(fileTypeFilter->currentText() == "Headers")
    {
        for(index = 0; index < informationOfHeaderFiles.length(); index++)
        {
            addFileUI(informationOfHeaderFiles.at(index));
        }
    }
    else if(fileTypeFilter->currentText() == "Source Files")
    {
        for(index = 0; index < informationOfSourceFiles.length(); index++)
        {
            addFileUI(informationOfSourceFiles.at(index));
        }
    }
}
void ClassCombinerUserInterface::sortFiles(bool ignore)
{
    ignore;
    filesToCombine->sortItems(Qt::AscendingOrder);
}
void ClassCombinerUserInterface::sortFolders(bool ignore)
{
    ignore;
    foldersToCombine->sortItems(Qt::AscendingOrder);
}
void ClassCombinerUserInterface::filterChanged(QString text)
{
    if(text == "Headers")
    {
        filesToCombine->clear();
        int index = 0;
        for(index = 0; index < informationOfHeaderFiles.length(); index++)
        {
            addFileUI(informationOfHeaderFiles.at(index));
        }
    }
    else if(text == "Source Files")
    {
        filesToCombine->clear();
        int index = 0;
        for(index = 0; index < informationOfSourceFiles.length(); index++)
        {
            addFileUI(informationOfSourceFiles.at(index));
        }
    }
}
QString ClassCombinerUserInterface::shortName(QString text)
{
    QString result = "";
    int index = 0, startingIndex = 0;
    for(index = text.length() - 1; index >= 0; index--)
    {
        if(text.at(index) == '/')
        {
            startingIndex = index;
            break;
        }
    }

    for(index = startingIndex + 1; index < text.length(); index++)
    {
        result += text.at(index);
    }

    return result;
}

// ***** Part 2 Functions
void ClassCombinerUserInterface::selectHeaderFile(bool ignore)
{
    ignore;
    int index = 0;
    QString filter = "Headers (";
    for(index = 0; index < headerTypes.length(); index++)
    {
        filter += "*" + headerTypes.at(index);
        if(index < headerTypes.length() - 1)
        {
                  filter += " ";
        }
    }

    filter += ");; Sources (";
    for(index = 0; index < sourceTypes.length(); index++)
    {
        filter += "*" + sourceTypes.at(index);
        if(index < sourceTypes.length() - 1)
        {
                  filter += " ";
        }
    }
    filter += ");; All Files (*.*)";

    QString fileForSavingHeader = QFileDialog::getSaveFileName(this, tr("Resulting Header File For Synthesis"), "/home", filter);
    outputHeaderFile->setText(fileForSavingHeader);
}
void ClassCombinerUserInterface::selectSourceFile(bool ignore)
{
    ignore;
    int index = 0;
    QString filter = "Headers (";
    for(index = 0; index < headerTypes.length(); index++)
    {
        filter += "*" + headerTypes.at(index);
        if(index < headerTypes.length() - 1)
        {
                  filter += " ";
        }
    }

    filter += ");; Sources (";
    for(index = 0; index < sourceTypes.length(); index++)
    {
        filter += "*" + sourceTypes.at(index);
        if(index < sourceTypes.length() - 1)
        {
                  filter += " ";
        }
    }
    filter += ");; All Files (*.*)";

    QString fileForSavingHeader = QFileDialog::getSaveFileName(this, tr("Resulting Source File For Synthesis"), "/home", filter);
    outputSourceFile->setText(fileForSavingHeader);
}

// ***** Part 3 Functions
void ClassCombinerUserInterface::fileTypeSelectorFunction(QString text)
{
    int index = 0;
    if(text == "Headers")
    {
        fileSelector->clear();

        for(index = 0; index < informationOfHeaderFiles.length(); index++)
        {
            fileSelector->addItem(shortName(informationOfHeaderFiles.at(index)));
        }
    }
    else if(text == "Sources")
    {
        fileSelector->clear();

        for(index = 0; index < informationOfSourceFiles.length(); index++)
        {
            fileSelector->addItem(shortName(informationOfSourceFiles.at(index)));
        }
    }
}
void ClassCombinerUserInterface::fileSelectorFunction(QString text)
{
    int indexOfCurrentlySelected = 0;
    int indexOfDependency = 0;
    int index = 0;

    // Find the index of the file
    for(index = 0; index < informationOfFiles.length(); index++)
    {
        if(informationOfFiles.at(index).endsWith(text))
        {
            indexOfCurrentlySelected = index;
            break;
        }
    }

    // Setup the table as approriate
    informationDisplayTable->setColumnCount(0);
    informationDisplayTable->setRowCount(0);
    informationDisplayTable->setColumnCount(2);
    informationDisplayTable->setRowCount(dependenciesOfFiles.at(indexOfCurrentlySelected).length());

    // Fill up these rows and columns with QLineEdit's which are read only
    for(index = 0; index < informationDisplayTable->rowCount(); index++)
    {
        for(indexOfDependency = 0; indexOfDependency < informationDisplayTable->columnCount(); indexOfDependency++)
        {
            informationDisplayTable->setCellWidget(index, indexOfDependency, new QLineEdit());
            qobject_cast<QLineEdit*>(informationDisplayTable->cellWidget(index, indexOfDependency))->setReadOnly(true);
        }
    }

    // Fill up the columns with dependency on left side, and the part that fills up the dependency on the other
    // Also use the solutions from "uniqueDependencies" and "dependencyFillingList" to give easy options to assign
    for(index = 0; index < informationDisplayTable->rowCount(); index++)
    {
        // Insert the dependencies
        if(qobject_cast<QLineEdit*>(informationDisplayTable->cellWidget(index, 0)) != NULL)
        {
            //std::cout << "Table text - " << row << "," << column << " - " << replacementText << std::endl;
            qobject_cast<QLineEdit*>(informationDisplayTable->cellWidget(index, 0))->setText(dependenciesOfFiles.at(indexOfCurrentlySelected).at(index));
        }
        
        // Insert the first option of the list of matching possibilities
        indexOfDependency = uniqueDependencies.indexOf(dependenciesOfFiles.at(indexOfCurrentlySelected).at(index));
        // Inser the dependency filler
        if(qobject_cast<QLineEdit*>(informationDisplayTable->cellWidget(index, 1)) != NULL)
        {
            //std::cout << "Table text - " << row << "," << column << " - " << replacementText << std::endl;
            //qobject_cast<QLineEdit*>(informationDisplayTable->cellWidget(index, 1))->setText(dependencyFillingList.at(indexOfDependency).at(0));
        }
    }

    if(dependencyListType->currentText() == "Current File")
    {
        listOfDependencies->clear();
        for(index = 0; index < dependenciesOfFiles.at(indexOfCurrentlySelected).length(); index++)
        {
            listOfDependencies->addItem(dependenciesOfFiles.at(indexOfCurrentlySelected).at(index));
        }
    }
}

// ***** Part 4 Functions
void ClassCombinerUserInterface::dependencyDisplay(QString text)
{
    int index = 0;
    listOfDependencies->clear();
    text = dependencyListType->currentText();
    if(text == "Current File")
    {
        fileSelectorFunction(fileSelector->currentText());
    }
    else if(text == "All")
    {
        for(index = 0; index < uniqueDependencies.length(); index++)
        {
            listOfDependencies->addItem(uniqueDependencies.at(index));
        }
    }
    else if(text == "All Unassigned")
    {
        for(index = 0; index < uniqueDependencies.length(); index++)
        {
            if(dependencyFillingList.at(index).length() == 0)
            {
                listOfDependencies->addItem(uniqueDependencies.at(index));
            }
        }
    }
    else if(text == "All Assigned")
    {
        for(index = 0; index < uniqueDependencies.length(); index++)
        {
            if(dependencyFillingList.at(index).length() > 0)
            {
                listOfDependencies->addItem(uniqueDependencies.at(index));
            }
        }
    }

    dependencySolutionList(listOfDependencies->currentText());
}
void ClassCombinerUserInterface::dependencySolutionList(QString text)
{
    int indexOfCurrentlySelected = uniqueDependencies.indexOf(text);
    assignedDependency->clear();

    if(indexOfCurrentlySelected >= 0 && dependencyFillingList.at(indexOfCurrentlySelected).length() > 0)
    {
        int index = 0;
        for(index = 0; index < dependencyFillingList.at(indexOfCurrentlySelected).length(); index++)
        {
            assignedDependency->addItem(dependencyFillingList.at(indexOfCurrentlySelected).at(index));
        }
    }
    else
    {
        assignedDependency->addItem("None");
    }
}
void ClassCombinerUserInterface::addDependencyFunction(bool ignore)
{
    ignore;
    int index = 0;
    QString filter = "Headers (";
    for(index = 0; index < headerTypes.length(); index++)
    {
        filter += "*" + headerTypes.at(index);
        if(index < headerTypes.length() - 1)
        {
                  filter += " ";
        }
    }

    filter += ");; Sources (";
    for(index = 0; index < sourceTypes.length(); index++)
    {
        filter += "*" + sourceTypes.at(index);
        if(index < sourceTypes.length() - 1)
        {
                  filter += " ";
        }
    }
    filter += ");; All Files (*.*)";

    QString fileDependency = QFileDialog::getOpenFileName(this, tr("Open Header/Source Files"), "/home", filter);

    // Assign the file dependency to the "AssingedDependency" list and use the "ListOfDependencies" to restructure "DependencyFillingList"
    assignedDependency->addItem(shortName(fileDependency));
    index  = uniqueDependencies.indexOf(listOfDependencies->currentText());

    if(index >= 0)
    {
        if(dependencyFillingList.at(index).contains(fileDependency))
        {
            dependencyFillingList[index].remove(index);
            dependencyFillingList[index].prepend(fileDependency);
        }
        else
        {
            dependencyFillingList[index].prepend(fileDependency);
        }
    }
}
void ClassCombinerUserInterface::assignDependency(bool ignore)
{
    ignore;

    // Ensure the dependency is at the top of the solution list
    int index = uniqueDependencies.indexOf(listOfDependencies->currentText());
    QString fileDependency = assignedDependency->currentText();
    if(index >= 0)
    {
        if(dependencyFillingList.at(index).contains(fileDependency))
        {
            dependencyFillingList[index].remove(index);
            dependencyFillingList[index].prepend(fileDependency);
        }
        else
        {
            dependencyFillingList[index].prepend(fileDependency);
        }
    }
    dependencySolutionList(listOfDependencies->currentText());
}

// ***** Part 6 Functions
void ClassCombinerUserInterface::openDialog(bool ignore)
{
    ignore;
    headerAndSourceTypesDialog->open(headerTypes, sourceTypes);
}
void ClassCombinerUserInterface::updateTypes(QVector<QString> headersTypesInput, QVector<QString> sourceTypesInput)
{
    int index = 0;
    headerTypes.clear();
    for(index = 0; index < headersTypesInput.length(); index++)
    {
        headerTypes.append(headersTypesInput.at(index));
    }

    sourceTypes.clear();
    for(index = 0; index < sourceTypesInput.length(); index++)
    {
        sourceTypes.append(sourceTypesInput.at(index));
    }
}
void ClassCombinerUserInterface::themeFunction(bool ignore)
{
    ignore;

}
void ClassCombinerUserInterface::refreshFunction(bool ignore)
{
    ignore;

    // Clear all the primary structural variables
    uniqueDependencies.clear();
    dependencyFillingList.clear();
    informationOfFiles.clear();
    informationOfHeaderFiles.clear();
    informationOfSourceFiles.clear();
    informationOfFolders.clear();
    stateOfDependenciesOfFiles.clear();
    informationContainedWithinFiles.clear();
    structureWeight.clear();

    // Clear the UI
    foldersToCombine->clear();
    filesToCombine->clear();
    outputHeaderFile->clear();
    outputSourceFile->clear();
    fileSelector->clear();
    informationDisplayTable->setRowCount(0);
    informationDisplayTable->setColumnCount(0);
    fileSelector->clear();
    listOfDependencies->clear();

    // Set state
    setState(0);
    statusBar->setText("All cleared.");

}
void ClassCombinerUserInterface::setState(int state)
{
    if(state == 0 && stateVariable != 0) // Not a single file - No header and source. No synthesis,
    {
        outputFileBox->setEnabled(true);
        fileInformationDisplayBox->setEnabled(false);
        dependencyAssignmentBox->setEnabled(false);
        primaryBox->setEnabled(false);
        structuralDecomposerBox->setEnabled(false);

        stateVariable = 0;
    }
    else if(state == 1 && stateVariable != 1) // A single file atleast, but no dependencies found
    {
        outputFileBox->setEnabled(true);
        fileInformationDisplayBox->setEnabled(true);
        dependencyAssignmentBox->setEnabled(true);
        primaryBox->setEnabled(true);
        structuralDecomposerBox->setEnabled(true);
        synthesizeButton->setEnabled(false);

        // Ensure the UI related to dependencies is updated
        dependencyDisplay(dependencyListType->currentText());

        stateVariable = 1;
    }
    else if(state == 2 && stateVariable != 2) // A single file and dependencies found
    {
        outputFileBox->setEnabled(true);
        fileInformationDisplayBox->setEnabled(true);
        dependencyAssignmentBox->setEnabled(true);
        primaryBox->setEnabled(true);
        structuralDecomposerBox->setEnabled(true);
        synthesizeButton->setEnabled(true);

        stateVariable = 2;
    }
}

// ***** Key Non-UI related functions for the program ******
void ClassCombinerUserInterface::findAllHeadersAndSourcesLocally(QString folderNameInput)
{
    QDir folderToAnalyze(folderNameInput);
    if(folderToAnalyze.isReadable())
    {
        QFileInfoList filesOfConcern = folderToAnalyze.entryInfoList(QStringList() << "*.h");

        QString location = "";
        int index = 0;
        for(index = 0; index < filesOfConcern.length(); index++)
        {
            location = filesOfConcern.at(index).absoluteFilePath();
            addFile(location);
        }

        filesOfConcern = folderToAnalyze.entryInfoList(QStringList() << "*.cpp");
        for(index = 0; index < filesOfConcern.length(); index++)
        {
            location = filesOfConcern.at(index).absoluteFilePath();
            addFile(location);
    }
    }

    // Set the UI to be correct
    filterChanged(fileTypeFilter->currentText());
}
void ClassCombinerUserInterface::recursiveSearch(QString sourceFolder)
{
    QDir source(sourceFolder);

    if(source.isReadable())
    {
        QStringList dirs = source.entryList(QDir::AllDirs);
        QVector<QString> subsequentDirectories;
        QString directoryLocation = "";

        // Add it to the directory reading
        addFolder(sourceFolder);

        int index = 0;
        // Find all the headers and sources locally
        findAllHeadersAndSourcesLocally(sourceFolder);

        // Find all the subdirectories
        subsequentDirectories.resize(0);
        for(index = 0; index < dirs.length(); index++)
        {
            if(!QString(dirs.at(index)).contains("."))
            {
                directoryLocation = sourceFolder + "/";
                directoryLocation += QString(dirs.at(index));
                subsequentDirectories.append(directoryLocation);
            }
        }

        // Apply local search in each subdirectory using this function, which will apply that to its subdirectories as well
        for(index = 0; index < subsequentDirectories.length(); index++)
        {
            recursiveSearch(subsequentDirectories.at(index));
        }
    }
}
void ClassCombinerUserInterface::analyzeFile(QString fileInput, int indexWithinStructure)
{
    QFile file(fileInput);

    if(file.exists() && file.open(QIODevice::ReadWrite))
    {
        //std::cout << "Here " << std::endl;

        QTextStream in(&file);
        QStringList lineAnalysis = in.readAll().split("\n");
        QString sourceInformation;

        int index = 0;
        for(index = 0; index < lineAnalysis.length(); index++)
        {
            //std::cout << "Line " << index << " - " << lineAnalysis.at(index).toStdString() << std::endl;
            if(QString(lineAnalysis.at(index)).contains("#include", Qt::CaseInsensitive) && QString(lineAnalysis.at(index)).startsWith('#'))
            {
                //std::cout << "Line " << index << " - " << lineAnalysis.at(index).toStdString() << std::endl;

                //std::cout << analyzeIncludeStatement(QString(lineAnalysis.at(index))).toStdString() << std::endl;
                (dependenciesOfFiles[indexWithinStructure]).append(analyzeIncludeStatement(QString(lineAnalysis.at(index))));
                (stateOfDependenciesOfFiles[indexWithinStructure]).append(false);
            }
            else
            {
                sourceInformation += QString(lineAnalysis.at(index));
            }
        }

        //std::cout << sourceInformation.toStdString() << std::endl;
        //informationContainedWithinFiles.replace(indexWithinStructure, sourceInformation);
    }
}
QString ClassCombinerUserInterface::analyzeIncludeStatement(QString text)
{
    QString result;

    //std::cout << text.toStdString() << std::endl;

    int index = 0;
    bool add = false;
    if(text.contains('<') && text.contains('>'))
    {
        //std::cout << "Here " << std::endl;

        for(index = 0; index < text.length(); index++)
        {
            if(text.at(index) == '<')
            {
                add = true;
            }

            if(text.at(index) == '>')
            {
                add = false;
            }

            if(add && text.at(index) != '<')
            {
                //std::cout << "Adding " << QString(text.at(index)).toStdString() << std::endl;
                result.append(text.at(index));
            }
        }

    }
    else if(text.contains('\"'))
    {
        bool firstIndicator = false;
        bool secondIndicator = false;

        //std::cout << "Here " << std::endl;

        for(index = 0; index < text.length(); index++)
        {
            if(firstIndicator && text.at(index) == '\"')
            {
                secondIndicator = true;
                add = false;
            }

            if(!secondIndicator && text.at(index) == '\"')
            {
                add = true;
                firstIndicator = true;
            }

            if(add && (text.at(index) != '\"'))
            {
                result.append(text.at(index));
            }
        }
    }

    return result.remove("\n");
}
// Ensures structural similarity when things increase
void ClassCombinerUserInterface::ensureStructuralCoherence()
{
    int lengthIndex = informationOfFiles.length();
    int indexOfAddition = lengthIndex - 1;

    // Ensure all sizes are the same. Mainly, increase if necessary
    informationContainedWithinFiles.resize(lengthIndex);
    dependenciesOfFiles.resize(lengthIndex);
    stateOfDependenciesOfFiles.resize(lengthIndex);
    structureWeight.resize(lengthIndex);

    // Add the file to remaining UI
    fileTypeSelectorFunction(fileTypeSelector->currentText());

    // Analyze the file now!
    //QString status = "Analyzing file and extracting source of " + informationOfFiles[indexOfAddition];
    //status += ".";
    //statusBar->setText(status);
    analyzeFile(informationOfFiles[indexOfAddition], indexOfAddition);

    // Check for any new unique dependencies
    //status = "Analyzing dependencies of " + informationOfFiles[indexOfAddition];
    //status += ".";
    //statusBar->setText(status);
    int index = 0;
    for(index = 0; index < dependenciesOfFiles.at(indexOfAddition).length(); index++)
    {
        if(!uniqueDependencies.contains(dependenciesOfFiles.at(indexOfAddition).at(index)))
        {
            uniqueDependencies.append(dependenciesOfFiles.at(indexOfAddition).at(index));
            dependencyFillingList.resize(uniqueDependencies.length());
        }
    }

    //status = "Done analyzing " + informationOfFiles[indexOfAddition];
    //status += ".";
    //statusBar->setText(status);
}
// Ensures structural coherence whenever things decrease
void ClassCombinerUserInterface::ensureStructuralCoherence(int indexOfRemoval)
{
    informationContainedWithinFiles.remove(indexOfRemoval);
    dependenciesOfFiles.remove(indexOfRemoval);
    stateOfDependenciesOfFiles.remove(indexOfRemoval);
    structureWeight.remove(indexOfRemoval);
}
// Finds the solution to the dependencies
void ClassCombinerUserInterface::analyzeAll(bool ignore)
{
    ignore;

    if(informationOfFiles.length() > 0)
    {
        int index = 0;
        for(index = 0; index < informationOfFiles.length(); index++)
        {
            findFileDependencies(index);
        }

        fileSelectorFunction(fileSelector->currentText());
        dependencySolutionList(listOfDependencies->currentText());
    }

    setState(2);
}
// Finds solution at dependency. Finds the file at the given index, the dependencies at the index, and attempts to solve the index
void ClassCombinerUserInterface::findFileDependencies(int index)
{
    index;
}
// Combines files by analyzing the dependencies and their solutions
void ClassCombinerUserInterface::synthesize(bool ignore)
{
    ignore;

    // Analyze Files
    int index = 0;

}

// ******* HeaderAndSourcesTypesDialog ******* //
HeaderAndSourceTypesDialog::HeaderAndSourceTypesDialog()
{
    layout = new QGridLayout;
    status = false;

    headerTypesWidget = new QListWidget;
    addHeaderTypes = new QPushButton;
    addHeaderTypes->setIcon(QIcon(":/images/Images/Add.ico"));
    connect(addHeaderTypes, SIGNAL(clicked(bool)), this, SLOT(addHeaderTypesFunction(bool)));
    removeHeaderTypes = new QPushButton;
    removeHeaderTypes->setIcon(QIcon(":/images/Images/Subtract.png"));
    connect(removeHeaderTypes, SIGNAL(clicked(bool)), this, SLOT(removeHeaderTypesFunction(bool)));

    sourceTypesWidget = new QListWidget;
    addSourceTypes = new QPushButton;
    addSourceTypes->setIcon(QIcon(":/images/Images/Add.ico"));
    connect(addSourceTypes, SIGNAL(clicked(bool)), this, SLOT(addSourceTypesFunction(bool)));
    removeSourceType = new QPushButton;
    removeSourceType->setIcon(QIcon(":/images/Images/Subtract.png"));
    connect(removeSourceType, SIGNAL(clicked(bool)), this, SLOT(removeSourceTypesFunction(bool)));

    accept = new QPushButton;
    accept->setText("Accept");
    connect(accept, SIGNAL(clicked(bool)), this, SLOT(hideOrOpen(bool)));

    // Set layout
    layout->addWidget(new QLabel("Headers"), 0, 0, 1, 3, Qt::AlignCenter);
    layout->addWidget(headerTypesWidget, 1, 0, 4, 3);
    layout->addWidget(addHeaderTypes, 5, 1, 1, 1);
    layout->addWidget(removeHeaderTypes, 5, 2, 1, 1);
    layout->addWidget(new QLabel("Sources"), 0, 3, 1, 3, Qt::AlignCenter);
    layout->addWidget(sourceTypesWidget, 1, 3, 4, 3);
    layout->addWidget(addSourceTypes, 5, 4, 1, 1);
    layout->addWidget(removeSourceType, 5, 5, 1, 1);
    layout->addWidget(accept, 6, 4, 1, 2);

    this->setModal(true);
    this->setLayout(layout);
    this->setWindowTitle("Header And Source Types");
}
void HeaderAndSourceTypesDialog::closeEvent(QCloseEvent *ev)
{
    ev;
    hideOrOpen(false);
}
void HeaderAndSourceTypesDialog::hideOrOpen(bool ignore)
{
    ignore;

    if(status)
    {
        status = false;
        this->setVisible(false);
        this->hide();

        // Setup the vectors
        QVector<QString> headerTypes;
        QVector<QString> sourceTypes;
        int index = 0;
        for(index = 0; index < headerTypesWidget->count(); index++)
        {
            headerTypes.append(headerTypesWidget->item(index)->text());
        }
        for(index = 0; index < sourceTypesWidget->count(); index++)
        {
            sourceTypes.append(sourceTypesWidget->item(index)->text());
        }

        emit updateTypes(headerTypes, sourceTypes);

    }
    else
    {
        status = true;
        this->setVisible(true);
        this->show();
    }
}
void HeaderAndSourceTypesDialog::open(QVector<QString> headerTypes, QVector<QString> sourceTypes)
{
    headerTypesWidget->clear();
    sourceTypesWidget->clear();

    int index = 0;
    for(index = 0; index < headerTypes.length(); index++)
    {
        headerTypesWidget->addItem(headerTypes.at(index));
    }
    for(index = 0; index < sourceTypes.length(); index++)
    {
        sourceTypesWidget->addItem(sourceTypes.at(index));
    }

    hideOrOpen(false);
}
void HeaderAndSourceTypesDialog::addHeaderTypesFunction(bool ignore)
{
    ignore;
    bool ok;
    QString text = QInputDialog::getText(this, tr("Define Header File Type"),
                                         tr("Header Type:"), QLineEdit::Normal,
                                         ".", &ok);
    if(ok && !text.isEmpty())
    {
        if(text.contains(".") && text.length() > 1)
        {
            headerTypesWidget->addItem(text);
        }
    }
}
void HeaderAndSourceTypesDialog::addSourceTypesFunction(bool ignore)
{
    ignore;
    bool ok;
    QString text = QInputDialog::getText(this, tr("Define Source File Type"),
                                         tr("Source Type:"), QLineEdit::Normal,
                                         ".", &ok);
    if(ok && !text.isEmpty())
    {
        if(text.contains(".") && text.length() > 1)
        {
            sourceTypesWidget->addItem(text);
        }
    }
}
void HeaderAndSourceTypesDialog::removeHeaderTypesFunction(bool ignore)
{
    ignore;
    int indexOfCurrentlySelected = headerTypesWidget->currentRow();
    if(indexOfCurrentlySelected >= 0 && indexOfCurrentlySelected < headerTypesWidget->count())
    {
        headerTypesWidget->takeItem(indexOfCurrentlySelected);
    }
}
void HeaderAndSourceTypesDialog::removeSourceTypesFunction(bool ignore)
{
    ignore;
    int indexOfCurrentlySelected = sourceTypesWidget->currentRow();
    if(indexOfCurrentlySelected >= 0 && indexOfCurrentlySelected < sourceTypesWidget->count())
    {
        sourceTypesWidget->takeItem(indexOfCurrentlySelected);
    }
}

/*
From Synthesize(bool ignore)
// Resize source, weight, dependencies and bool structure
informationContainedWithinFiles.resize(0);
informationContainedWithinFiles.resize(informationOfFiles.length());
dependenciesOfFiles.resize(0);
dependenciesOfFiles.resize(informationOfFiles.length());
stateOfDependenciesOfFiles.resize(0);
stateOfDependenciesOfFiles.resize(informationOfFiles.length());
structureWeight.resize(0);
structureWeight.resize(informationOfFiles.length());
*/
// Excess code from addFile(QString file)
/*
if(!informationOfFiles.contains(file))
{
    informationOfFiles.append(file);

    if(file.endsWith(".h"))
    {
        informationOfHeaderFiles.append(file);

        if(fileTypeFilter->currentText() == "Headers")
        {
            if(filesNameForm->currentText() == "Long")
            {
                filesToCombine->addItem(file);
            }
            else if(filesNameForm->currentText() == "Short")
            {
                filesToCombine->addItem(shortName(file));
            }
        }
    }
    else if(file.endsWith(".cpp"))
    {
        informationOfSourceFiles.append(file);

        if(fileTypeFilter->currentText() == "Source Files")
        {
            if(filesNameForm->currentText() == "Long")
            {
                filesToCombine->addItem(file);
            }
            else if(filesNameForm->currentText() == "Short")
            {
                filesToCombine->addItem(shortName(file));
            }
        }
    }
}
if(checkForDegeneracy(filesToAdd.at(index)))
{
    informationOfFiles.append(filesToAdd.at(index));

    if(QString(filesToAdd.at(index)).endsWith(".h") && fileTypeFilter->currentText() == "Headers")
    {
        informationOfHeaderFiles.append(QString(filesToAdd.at(index)));

        if(filesNameForm->currentText() == "Long")
        {
            filesToCombine->addItem(QString(filesToAdd.at(index)));
        }
        else if(filesNameForm->currentText() == "Short")
        {
            filesToCombine->addItem(shortName(QString(filesToAdd.at(index))));
        }
    }
    else if(QString(filesToAdd.at(index)).endsWith(".cpp") && fileTypeFilter->currentText() == "Source Files")
    {
        informationOfSourceFiles.append(QString(filesToAdd.at(index)));

        if(filesNameForm->currentText() == "Long")
        {
            filesToCombine->addItem(QString(filesToAdd.at(index)));
        }
        else if(filesNameForm->currentText() == "Short")
        {
            filesToCombine->addItem(shortName(QString(filesToAdd.at(index))));
        }
    }
}
*/
