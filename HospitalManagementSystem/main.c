 /* Name: Bünyamin YAVUZ, Number: 200254018 Lecture: COM 201_HW_1 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The main structure of the struct array
struct HospitalList {

    char firstLetter;
    struct Record *firstRecordPtr;

};

// The structure of a record which has patient's informations(name, surname, person id, polyclinic name)
struct Record {

        char name[50];
        char surname[50];
        int personId;
        char polyclinic[50];
        struct Record *nextRecord;

 };

// Creating a static struct array from the struct HospitalList
struct HospitalList hospitallist[26];

// To show the current patient's informations
void display(){

    // Creating a temporary record to traverse the linked list
	struct Record *temporaryRecord = (struct Record*)malloc(sizeof(struct Record));

	// Creating a index variable to traverse in the static array(hospitallist[26])
	int indexOfhospitallist=0;

	int c;

        // Checks up whether there exist a record
	    for(c='A',indexOfhospitallist=0;c<='Z';c++,indexOfhospitallist++){
    	if(hospitallist[indexOfhospitallist].firstRecordPtr == NULL){
    		continue;
		}
		else{
			if(hospitallist[indexOfhospitallist].firstRecordPtr == NULL){
				continue;
			}

			// There exist record so show them
			else{
			temporaryRecord=hospitallist[indexOfhospitallist].firstRecordPtr;

            // Shows the patient's informations
			while(temporaryRecord != NULL){
				printf("NAME : %s\n",temporaryRecord->name);
				printf("SURNAME : %s\n",temporaryRecord->surname);
				printf("PERSON ID : %d\n",temporaryRecord->personId);
				printf("POLYCLINIC NAME : %s\n\n",temporaryRecord->polyclinic);
				temporaryRecord=temporaryRecord->nextRecord;
			}
			}
		}
	}

}


void displaySortedRecordsByName(){

    printf(">>>>>>>>>>   LIST OF CURRENT REGISTERED PATIENTS SORTED BY NAME  <<<<<<<<<<\n");

    // Creating a temporary record to traverse the linked list
	struct Record *temporaryRecord = (struct Record*)malloc(sizeof(struct Record));
	// Creating a index variable to traverse in the static array(hospitallist[26])
	int indexOfhospitallist=0;
	int c;

	    for(c='A',indexOfhospitallist=0;c<='Z';c++,indexOfhospitallist++){
    	if(hospitallist[indexOfhospitallist].firstRecordPtr ==NULL){
    		continue;
		}
		else{
			if(hospitallist[indexOfhospitallist].firstRecordPtr == NULL){
				continue;
			}
			else{
			temporaryRecord=hospitallist[indexOfhospitallist].firstRecordPtr;


			while(temporaryRecord != NULL){
				printf("NAME : %s\n",temporaryRecord->name);
				temporaryRecord=temporaryRecord->nextRecord;
			}
			}
		}
	}

}



void displaySortedRecordsBySurname(){

    printf(">>>>>>>>>>   LIST OF CURRENT REGISTERED PATIENTS SORTED BY SURNAME  <<<<<<<<<<\n");
    // Creating a temporary record to traverse the linked list
	struct Record *temporaryRecord = (struct Record*)malloc(sizeof(struct Record));

	// Creating a index variable to traverse in the static array(hospitallist[26])
	int indexOfhospitallist=0;
	int c;

	    for(c='A',indexOfhospitallist=0;c<='Z';c++,indexOfhospitallist++){
    	if(hospitallist[indexOfhospitallist].firstRecordPtr ==NULL){
    		continue;
		}
		else{
			if(hospitallist[indexOfhospitallist].firstRecordPtr == NULL){
				continue;
			}
			else{
			temporaryRecord=hospitallist[indexOfhospitallist].firstRecordPtr;


			while(temporaryRecord != NULL){
				printf("SURNAME : %s\n",temporaryRecord->surname);
				temporaryRecord=temporaryRecord->nextRecord;
			}
			}
		}
	}

}



void displaySortedRecordsByPolyclinicName(){

    printf(">>>>>>>>>>   LIST OF CURRENT REGISTERED PATIENTS SORTED BY POLYCLINIC NAME  <<<<<<<<<<\n");
    // Creating a temporary record to traverse the linked list
	struct Record *temporaryRecord = (struct Record*)malloc(sizeof(struct Record));
	// Creating a index variable to traverse in the static array(hospitallist[26])
	int indexOfhospitallist=0;
	int c;
	    for(c='A',indexOfhospitallist=0;c<='Z';c++,indexOfhospitallist++){
    	if(hospitallist[indexOfhospitallist].firstRecordPtr ==NULL){
    		continue;
		}
		else{
			if(hospitallist[indexOfhospitallist].firstRecordPtr == NULL){
				continue;
			}
			else{
			temporaryRecord=hospitallist[indexOfhospitallist].firstRecordPtr;

			while(temporaryRecord != NULL){
				printf("POLYCLINIC : %s\n",temporaryRecord->polyclinic);
				temporaryRecord=temporaryRecord->nextRecord;
			}
			}
		}
	}

}



void AddNewRecord(char Name[50],char Surname[50],int PersonId,char Polyclinic[50]){

    // Creating a temporary record to traverse the linked list
    struct Record *temporaryRecord = (struct Record *)malloc(sizeof(struct Record));
	int c = 'A';

	// Creating a index variable to traverse in the static array(hospitallist[26])
	int indexOfhospitallist =0;

	// Creating a new record for a new patient's information
	struct Record *newN=NULL;
	newN=(struct Record*)malloc(sizeof(struct Record));

	// Setting the information to the created record
	strcpy(newN->name,Name);
	strcpy(newN->surname,Surname);
	strcpy(newN->polyclinic,Polyclinic);
	newN->personId=PersonId;
	newN->nextRecord=NULL;

	for(c='A',indexOfhospitallist=0;c<='Z';c++,indexOfhospitallist++){
		if(Name[0]==hospitallist[indexOfhospitallist].firstLetter && hospitallist[indexOfhospitallist].firstRecordPtr==NULL){

			hospitallist[indexOfhospitallist].firstRecordPtr = newN;
			break;

		}
		else{
			if(hospitallist[indexOfhospitallist].firstRecordPtr==NULL){
				continue;
			}
			else{
				temporaryRecord = hospitallist[indexOfhospitallist].firstRecordPtr;

			while(temporaryRecord->nextRecord!=NULL){
				temporaryRecord =temporaryRecord->nextRecord;
			}
			temporaryRecord->nextRecord=newN;
			break;
			}

		}
    }
    // To show the list of current registered patients
    display();
}



void SearchRecord(char Name[50],char Surname[50],char Polyclinic[50]){

    // Creating a temporary record to traverse the linked list
	struct Record *temporaryRecord = (struct Record*)malloc(sizeof(struct Record));

	// Creating a index variable to traverse in the static array(hospitallist[26])
    int indexOfhospitallist = 0;

    while(indexOfhospitallist < 26){
    // Comparing whether first letter of the patient's name with respect to the letter of the static list which belongs to the current index
    if (hospitallist[indexOfhospitallist].firstLetter == Name[0]){
         break;
    }indexOfhospitallist++;
    }
    temporaryRecord = hospitallist[indexOfhospitallist].firstRecordPtr;

    if(temporaryRecord==NULL){
    	return;

	}
	else{
		while(strcmp(temporaryRecord->name,Name)!=0 && temporaryRecord->nextRecord !=NULL){
    	temporaryRecord=temporaryRecord->nextRecord;
	}
	    while(strcmp(temporaryRecord->surname,Surname)!=0 && temporaryRecord->nextRecord !=NULL){
    	temporaryRecord=temporaryRecord->nextRecord;
	}
	    while(strcmp(temporaryRecord->polyclinic,Polyclinic)!=0 && temporaryRecord->nextRecord !=NULL){
		temporaryRecord=temporaryRecord->nextRecord;
	}

	if(strcmp(Name,temporaryRecord->name) == 0){
		if(strcmp(Surname,temporaryRecord->surname)==0){
			if(strcmp(Polyclinic,temporaryRecord->polyclinic)==0){
				printf("You searched for NAME : %s,SURNAME : %s,POLYCLINIC : %s(Extra information PERSON ID : %d)\n\n",temporaryRecord->name,temporaryRecord->surname,temporaryRecord->polyclinic,temporaryRecord->personId);
			}
		}

	}
	else{
		printf("Error");
	}
}
}



void DeleteRecord(char Name[50],char Surname[50],char Polyclinic[50]){

    // Creating a temporary record to traverse the linked list
	struct Record *temporaryRecord = (struct Record*)malloc(sizeof(struct Record));

	// Creating a index variable to traverse in the static array(hospitallist[26])
	int indexOfhospitallist = 0;

    while(indexOfhospitallist < 26){

    if (hospitallist[indexOfhospitallist].firstLetter == Name[0]){
         break;
    }indexOfhospitallist++;
    }

    temporaryRecord = hospitallist[indexOfhospitallist].firstRecordPtr;
    if(temporaryRecord==NULL){
    	return;

	}

	else{
		if(strcmp(temporaryRecord->name,Name)!=0 && temporaryRecord->nextRecord !=NULL){
			if(strcmp(temporaryRecord->surname,Surname)!=0 && temporaryRecord->nextRecord !=NULL){
				if(strcmp(temporaryRecord->polyclinic,Polyclinic)!=0 && temporaryRecord->nextRecord !=NULL){
					temporaryRecord = temporaryRecord->nextRecord;
					free(temporaryRecord);

					}
				}
			}
		else{
			if(strcmp(temporaryRecord->nextRecord->name,Name)!=0 && temporaryRecord->nextRecord !=NULL){
			if(strcmp(temporaryRecord->nextRecord->surname,Surname)!=0 && temporaryRecord->nextRecord !=NULL){
				if(strcmp(temporaryRecord->nextRecord->polyclinic,Polyclinic)!=0 && temporaryRecord->nextRecord !=NULL){
					temporaryRecord->nextRecord = temporaryRecord->nextRecord->nextRecord;
					free(temporaryRecord->nextRecord);

					}
				}
			}
		}


	}
	display();
}



void SortRecordsByName(){

    // Creating two temporary records to traverse the linked list
	struct Record *temporaryRecord = (struct Record*)malloc(sizeof(struct Record));
	struct Record *temporaryRecord2 = (struct Record*)malloc(sizeof(struct Record));

	// Creating a index variable to traverse in the static array(hospitallist[26])
	int indexOfhospitallist = 0;
	int c;

    while(indexOfhospitallist<26){
    	if(hospitallist[indexOfhospitallist].firstRecordPtr!=NULL){

    		temporaryRecord = hospitallist[indexOfhospitallist].firstRecordPtr;
    		while(temporaryRecord->nextRecord!=NULL){

    			if(strcmp(temporaryRecord->name,temporaryRecord->nextRecord->name) > 0){
    			strcpy(temporaryRecord2->name,temporaryRecord->name);
    			strcpy(temporaryRecord->name,temporaryRecord->nextRecord->name) ;
    			strcpy(temporaryRecord->nextRecord->name,temporaryRecord2->name);
			}
			temporaryRecord= temporaryRecord->nextRecord;
			}

		}indexOfhospitallist++;
	}

	// Display the sorted patient's name
	displaySortedRecordsByName();

}



void SortRecordsBySurname(){

    // Creating two temporary records to traverse the linked list
	struct Record *temporaryRecord = (struct Record*)malloc(sizeof(struct Record));
	struct Record *temporaryRecord2 = (struct Record*)malloc(sizeof(struct Record));

	// Creating a index variable to traverse in the static array(hospitallist[26])
	int indexOfhospitallist = 0;
	int c;


    while(indexOfhospitallist<26){

    	if(hospitallist[indexOfhospitallist].firstRecordPtr!=NULL){

    		temporaryRecord = hospitallist[indexOfhospitallist].firstRecordPtr;
    		while(temporaryRecord->nextRecord!=NULL){

    			if(strcmp(temporaryRecord->surname,temporaryRecord->nextRecord->surname) > 0){
    			strcpy(temporaryRecord2->surname,temporaryRecord->surname);
    			strcpy(temporaryRecord->surname,temporaryRecord->nextRecord->surname) ;
    			strcpy(temporaryRecord->nextRecord->surname,temporaryRecord2->surname);
			}
			temporaryRecord= temporaryRecord->nextRecord;
			}

		}indexOfhospitallist++;
	}
    // Display the sorted patient's surname
	displaySortedRecordsBySurname();
}



void SortRecordsByPolyclinicName(){

    // Creating two temporary records to traverse the linked list
	struct Record *temporaryRecord = (struct Record*)malloc(sizeof(struct Record));
	struct Record *temporaryRecord2 = (struct Record*)malloc(sizeof(struct Record));

	// Creating a index variable to traverse in the static array(hospitallist[26])
	int indexOfhospitallist = 0;
	int c;


    while(indexOfhospitallist<26){

    	if(hospitallist[indexOfhospitallist].firstRecordPtr!=NULL){

    		temporaryRecord = hospitallist[indexOfhospitallist].firstRecordPtr;
    		while(temporaryRecord->nextRecord!=NULL){

    			if(strcmp(temporaryRecord->polyclinic,temporaryRecord->nextRecord->polyclinic) > 0){
    			strcpy(temporaryRecord2->polyclinic,temporaryRecord->polyclinic);
    			strcpy(temporaryRecord->polyclinic,temporaryRecord->nextRecord->polyclinic) ;
    			strcpy(temporaryRecord->nextRecord->polyclinic,temporaryRecord2->polyclinic);
			}
			temporaryRecord= temporaryRecord->nextRecord;
			}

		}indexOfhospitallist++;
	}
    // Display the sorted patient's polyclinic name
	displaySortedRecordsByPolyclinicName();
}




int main(){

    // To select the action and implement it by using switch-case
    int selectedAction;
    int lastSelectedAction;

    // Required information types for programs
	char name[50];
	char surname[50];
	int personId;
	char polyclinic[50];



    // Interface of the menu
    printf("\n\n\n");
    printf("|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*| BENJAMIN HOSPITAL MANAGEMENT SYSTEM |*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|  \n\n\n");
    printf("\t\t\t\t|---|---|---WELCOME TO OUR HOSPITAL!---|---|---|\n\n");

    int indexOfhospitallist = 0;
    int c = 'A';

    // This loop is for creating a static structed array which has the letters from A to Z and a pointer which points the linked list of the that letter
    for(c = 'A'; c < 'Z'; c++, indexOfhospitallist++){

        hospitallist[indexOfhospitallist].firstLetter = c;
        hospitallist[indexOfhospitallist].firstRecordPtr = NULL;

    }

    // This loop for keeping the programs worked and serving the options again and again till the turn-off the programs
    while(selectedAction != 7){

        // To better see the new status in the terminal
        printf("\n\n\n");

        // All options that our menu has
        printf("<1> Add New Record\n\n");
        printf("<2> Search Record (with name, surname, and polyclinic name)\n\n");
        printf("<3> Delete Record (with name, surname, and polyclinic name)\n\n");
        printf("<4> Sort Records By Name\n\n");
        printf("<5> Sort Records By Surname\n\n");
        printf("<6> Sort Records By Polyclinic Name\n\n");
        printf("<7> Exit\n");

        // Selection section is here
        printf("SELECT THE ACTION YOU WANT TO DO FROM THE MENU : ");
        scanf("%d",&selectedAction);

        // To better see the new status in the terminal
        printf("\n\n\n");
    // If you want to clean the screen after choosing the case you can use(using it here is the best way) -> system("cls");

    // Selected action determines the progress
    switch(selectedAction){

    // Inserting a new record which has a new patient's informations(name, surname, person id, polyclinic name)
    case 1:
        printf("Please enter the patient's name(Please start with a capital letter!!!) : ");
        scanf("%s",&name);
        printf("Please enter the patient's surname(Please start with a capital letter!!!) : ");
        scanf("%s",&surname);
        printf("Please enter the patient's person id : ");
        scanf("%d",&personId);
        printf("Please enter the patient's polyclinic name(Please start with a capital letter!!!) : ");
        scanf("%s",&polyclinic);
        // To better see the new status in the terminal
        printf("\n\n");

        AddNewRecord(name,surname,personId,polyclinic);
        break;

    // Searching a record by getting the patient's informations(name, surname, polyclinic name)
    case 2:
        printf("Please enter the patient's name which will be searched(Please start with a capital letter!!!) : ");
        scanf("%s",&name);
        printf("Please enter the patient's surname which will be searched(Please start with a capital letter!!!) : ");
        scanf("%s",&surname);
        printf("Please enter the patient's polyclinic name which will be searched(Please start with a capital letter!!!) : ");
        scanf("%s",&polyclinic);

        // To better see the new status in the terminal
        printf("\n\n");

        SearchRecord(name,surname,polyclinic);
        break;

    // Deleting a record by getting the patient's informations(name, surname, polyclinic name)
    case 3:
        printf("Please enter the patient's name which will be deleted(Please start with a capital letter!!!) : ");
        scanf("%s",&name);
        printf("Please enter the patient's surname which will be deleted(Please start with a capital letter!!!) : ");
        scanf("%s",&surname);
        printf("Please enter the patient's polyclinic name which will be deleted(Please start with a capital letter!!!) : ");
        scanf("%s",&polyclinic);
        // To better see the new status in the terminal
        printf("\n\n");

        DeleteRecord(name,surname,polyclinic);
        break;

    // Sorting the records by entering the patient's informations(name)
    case 4:
        SortRecordsByName();
        break;

    // Sorting the records by entering the patient's informations(surname)
    case 5:
        SortRecordsBySurname();
        break;

    // Sorting the records by entering the patient's informations(polyclinic name)
    case 6:
        SortRecordsByPolyclinicName();
        break;

    // In switch-case case 7(exit)
    case 7:
        // It is for making sure the user about closing the program
        printf("Are you sure you are closing the program?(1 : Yes(close), 0 : No(continue)) : ");
        scanf("%d",&lastSelectedAction);
        if(lastSelectedAction == 0){
        // To better see the new status in the terminal
        printf("\n\n\n");

        // All options that our menu has
        printf("<1> Add New Record\n\n");
        printf("<2> Search Record (with name, surname, and polyclinic name)\n\n");
        printf("<3> Delete Record (with name, surname, and polyclinic name)\n\n");
        printf("<4> Sort Records By Name\n\n");
        printf("<5> Sort Records By Surname\n\n");
        printf("<6> Sort Records By Polyclinic Name\n\n");
        printf("<7> Exit\n");

        // Selection section is here
        printf("SELECT THE ACTION YOU WANT TO DO FROM THE MENU : ");
        scanf("%d",&selectedAction);

        // To better see the new status in the terminal
        printf("\n\n\n");

        }else{
            selectedAction = 7;
        }

        break;
    // Extra choice(case) to clean the screen
    /*

    case 8:
        system("cls");
    */

    // All other selections(Different form (1-7))
    default:
        // In switch-case case 7(exit)
        printf("SOMETHING WENT WRONG!!");
        selectedAction = 7;
        break;

    }
    }

    return 1;
}
