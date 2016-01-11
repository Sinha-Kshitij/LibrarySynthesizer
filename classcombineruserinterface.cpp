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
    sortFolderButton->setIcon(QIcon(":/images/Images/AZ_Sort.jpg"));
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
    folderAndFileLocationsBoxLayout->addWidget(new QLabel("Sort"), 6, 0, 1, 1);
    folderAndFileLocationsBoxLayout->addWidget(sortFolderButton, 6, 1, 1 ,1, Qt::AlignLeft);
    folderAndFileLocationsBoxLayout->addWidget(new QLabel("Display Form"), 6, 2, 1, 1);
    folderAndFileLocationsBoxLayout->addWidget(folderNameForm, 6, 3, 1, 1);
    
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
    sortFilesButton->setIcon(QIcon(":/images/Images/AZ_Sort.jpg"));
    filesNameForm = new QComboBox;
    filesNameForm->addItem("Long");
    filesNameForm->addItem("Short");
    connect(filesNameForm, SIGNAL(currentTextChanged(QString)), this, SLOT(filesNameDisplay(QString)));
    folderAndFileLocationsBoxLayout->addWidget(new QLabel("Files"), 0, 5, 1, 1);
    folderAndFileLocationsBoxLayout->addWidget(fileTypeFilter, 0,6 ,1, 1);
    folderAndFileLocationsBoxLayout->addWidget(fileRemoverButton, 0, 7, 1, 1);
    folderAndFileLocationsBoxLayout->addWidget(fileAdderButton, 0, 8, 1, 1);
    folderAndFileLocationsBoxLayout->addWidget(filesToCombine, 1, 5, 5, 4);
    folderAndFileLocationsBoxLayout->addWidget(new QLabel("Sort"), 6, 5, 1, 1);
    folderAndFileLocationsBoxLayout->addWidget(sortFilesButton, 6, 6, 1 ,1, Qt::AlignLeft);
    folderAndFileLocationsBoxLayout->addWidget(new QLabel("Display Form"), 6, 7, 1, 1);
    folderAndFileLocationsBoxLayout->addWidget(filesNameForm, 6, 8, 1, 1);
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
    connect(saveHeaderFileButton, SIGNAL(clicked(bool)), this, SLOT(selectHeaderFile(bool)));
    saveSourceFileButton = new QPushButton;
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

    // ***** Overall - Setup the overall UI *****
    classCombinerUserInterfaceLayout->addWidget(folderAndFileLocationsBox, 0, 0, 5, 5);
    classCombinerUserInterfaceLayout->addWidget(outputFileBox, 5, 0, 1, 3);
    classCombinerUserInterfaceLayout->addWidget(fileInformationDisplayBox, 0, 5, 3, 3);
    classCombinerUserInterfaceLayout->addWidget(dependencyAssignmentBox, 3, 5, 1, 3);
    classCombinerUserInterfaceLayout->addWidget(structuralDecomposerBox, 4, 5, 2, 3);
    this->setLayout(classCombinerUserInterfaceLayout);

    // Initialize the standard definitions
    headerTypes << ".h" << ".hxx";
    sourceTypes << ".cpp" << ".cxx";
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
}
void ClassCombinerUserInterface::addFolder(bool ignore)
{
    ignore;
    QString folderToAdd = QFileDialog::getExistingDirectory(this, tr("Open Directory for Header/Source Files"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if(addFolder(folderToAdd))
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
void ClassCombinerUserInterface::findAllHeadersAndSourcesLocally(QString folderNameInput)
{
    QDir folderToAnalyze(folderNameInput);
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

    // Set the UI to be correct
    filterChanged(fileTypeFilter->currentText());
}
void ClassCombinerUserInterface::recursiveSearch(QString sourceFolder)
{
    QDir source(sourceFolder);
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
    analyzeFile(informationOfFiles[indexOfAddition], indexOfAddition);
}

// Ensures structural coherence whenever things decrease
void ClassCombinerUserInterface::ensureStructuralCoherence(int indexOfRemoval)
{
    informationContainedWithinFiles.remove(indexOfRemoval);
    dependenciesOfFiles.remove(indexOfRemoval);
    stateOfDependenciesOfFiles.remove(indexOfRemoval);
    structureWeight.remove(indexOfRemoval);
}

void ClassCombinerUserInterface::synthesize()
{
    /*
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

    // Analyze Files
    int index = 0;



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

void ClassCombinerUserInterface::findFileDependencies(int index)
{

}


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
