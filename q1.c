
/*
Name: Begum Yonet
Id: 1179159
Date:10.14.2022
Assignment name: CIS2520 Data Structures II Assignment 2 Q1

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Car{
    char plateNumber[255];
    int mileage;
    int date;
    int moneyMade;
   
    struct Car *next;  
}Car;

float profit = 0;
void displaysAllLists(Car * avaliableRentedCars,Car*rentedCars,Car*inRepairedCars){
Car * tempNewCar = avaliableRentedCars;
Car* tempReturnCars= rentedCars;
Car* tempRepairCars = inRepairedCars;


// print all nodes in the available rented list
while(tempNewCar!=NULL){ // printing the all list in nodes
	printf("\nAvaliable Car:\nPlate Number: %s\nMileage: %d\nDate: %d\n",tempNewCar->plateNumber,tempNewCar->mileage,tempNewCar->date);
	tempNewCar= tempNewCar->next;
	
}
printf("\n");

// print all nodes in the available rented list
while(tempReturnCars!=NULL){ // printing the all list in nodes
	printf("Rented Car:\nPlate Number: %s\nMileage: %d\nDate: %d\n",tempReturnCars->plateNumber,tempReturnCars->mileage,tempReturnCars->date);
	tempReturnCars= tempReturnCars->next;
	
}
printf("\n");
// print all nodes in the available repair list
while(tempRepairCars!=NULL){
	printf("Car in Repair:\nPlate Number: %s\nMileage: %d\nDate: %d\n",tempRepairCars->plateNumber,tempRepairCars->mileage,tempRepairCars->date);
	tempRepairCars= tempRepairCars->next;
	
}

printf("\n");


}


void sortMile(Car ** head) {

  Car * currentNode = * head, * nextNode = NULL; // to make sure that they are equal to NULL 

  Car temp;

  if (head == NULL) {
    return;
  } else {

    while (currentNode != NULL) { // while loop until currentnode equal to the null 

      nextNode = currentNode -> next;  //  it will move on the next 

      while (nextNode != NULL) {
        if (currentNode -> mileage < nextNode -> mileage) { // next node's mileage is less than the current mileage

          temp.mileage = currentNode -> mileage;
          strcpy(temp.plateNumber, currentNode -> plateNumber);
          temp.date = currentNode->date;

          currentNode -> mileage = nextNode -> mileage;
          strcpy(currentNode -> plateNumber, nextNode -> plateNumber);
          currentNode -> date = nextNode -> date;

          nextNode -> mileage = temp.mileage;
          strcpy(nextNode -> plateNumber, temp.plateNumber); // it will copy into the temp
          nextNode -> date = temp.date;
        }

        nextNode = nextNode -> next;
      }

      currentNode = currentNode -> next;
    }
  }

}


void sortDate(Car ** head) {

  Car * currentNode = * head, * nextNode = NULL;

  Car temp = {"0",0,0};

  if (head == NULL) {
    return;
  } else {

    while (currentNode != NULL) {

      nextNode = currentNode -> next;

      while (nextNode != NULL) {
        if (currentNode -> date > nextNode -> date) {

          temp.mileage = currentNode -> mileage;
          strcpy(temp.plateNumber, currentNode -> plateNumber);
          temp.date = currentNode->date;

          currentNode -> mileage = nextNode -> mileage;
          strcpy(currentNode -> plateNumber, nextNode -> plateNumber);
          currentNode -> date = nextNode -> date;

          nextNode -> mileage = temp.mileage;
          strcpy(nextNode -> plateNumber, temp.plateNumber);
          nextNode -> date = temp.date;
        }

        nextNode = nextNode -> next;
      }

      currentNode = currentNode -> next;
    }
  }

}


void addCarToList(Car ** carList,Car * node){
 
		if(*carList == NULL){  // if it is empty it will add to the beginning
			  *carList = node;
}

    else if(carList!=NULL)   // if it is not it will add to the end of the list
    {
        Car *lastNode = *carList;
        
        while(lastNode->next != NULL) //  loop until the last one equal to the null 
        {
            lastNode = lastNode->next; // last node will point to the next
        }

        lastNode->next = node;
    }

}


Car * createCar(){
    Car *newCar = calloc(1,sizeof(Car)); // allocating memory for car
    getchar();
    printf("\n");
    // Getting the plate number from user
    printf("Enter The Car's Plate Number: ");
    fgets(newCar->plateNumber,255,stdin);
    newCar->plateNumber[strlen(newCar->plateNumber)-1 ] = '\0'; // to make sure the last character is null character

    // Getting the current mileage
    char charMileage[255];
    printf("Enter The Car's Current Mileage: ");
    fgets(charMileage,255,stdin);
    charMileage[strlen(charMileage)-1] = '\0';
    printf("\n");


    int mileage = atoi(charMileage); // changing str to an integer
    newCar->mileage = mileage;
    newCar->date =0; // date is 0 at this point
    newCar->next = NULL; // setting the next one to NULL  
    return newCar;
    
}

void calcProfit (int currentMileage,int returnedMileage){
    int calcMileage = returnedMileage - currentMileage;
    profit+=80.00;
    if (calcMileage>80){ // the difference between the return and current is bigger than 80
        int newMileage = calcMileage - 80;
        profit+=(0.15*newMileage);
    }

}

Car * DeleteCar(Car ** carList){

 int counter=0;
  int position;
  int i=0;

  Car *next;
  Car* countTemp=*carList;
  Car* temp = *carList;
    getchar();
    // Getting the plate number from user
    char plateNumber[255];
    printf("\n");
    printf("Enter The Car's Plate Number: ");
    fgets(plateNumber,255,stdin);
    plateNumber[strlen(plateNumber)-1 ] = '\0';

    // Getting the milega from user
    char charMileage[255];
    printf("Enter The Car's Return Mileage: ");
    fgets(charMileage,255,stdin);
    charMileage[strlen(charMileage)-1] = '\0';
    printf("\n");
    int currentMileage = atoi(charMileage); // convert string to integer  
    int found =0;
   
    
  while(countTemp!=NULL){
    if(strcmp(plateNumber,countTemp->plateNumber)==0){ // comparing the plate number  with user input

        if(currentMileage<countTemp->mileage){  // if the returned milage less than the exact milegae 
            printf("\nInvalid Milage\n"); // it is an error
            return 0;
        }
        found =1; // if we found it , it is true
        position = counter; // it will equal to overall findings
    }
    countTemp=countTemp->next; // move to the next
     counter++;  // increase the counter
  }

    if (found==0){  // it is not found it will equal to zero
        printf("\nCar not found\n");
        return 0;
    }

    Car * returnedCar = calloc(1,sizeof(Car)); // allocating memory

    if (position == 0)
    {
        *carList = temp->next;   
         strcpy(returnedCar->plateNumber,temp->plateNumber); // copying into the temp plateNumber
        calcProfit(temp->mileage,currentMileage);
         returnedCar->mileage = currentMileage;
         returnedCar->date = 0; // date equal to 0
         returnedCar->next = NULL;
        free(temp);            
        return returnedCar;
    }
    while(i<position-1){
       temp = temp->next; // temp will equal to the next
      i++;
    }

    next = temp->next->next;
    free(temp->next); 
    temp->next = next; 
    calcProfit(temp->mileage,currentMileage);
    returnedCar->mileage = currentMileage;
    returnedCar->date = 0;
    returnedCar->next = NULL;
    return returnedCar;

}



Car * TransferCar(Car ** carList){

    int counter = 0;
    int position = 0;
    int i = 0;
    Car *next;
    Car* countTemp = *carList;
    Car* temp = *carList;
    getchar();
    char plateNumber[255];
    printf("Enter The Car's Plate Number: ");
    fgets(plateNumber,255,stdin);
    plateNumber[strlen(plateNumber)-1 ] = '\0';
    int found = 0;
   

  while(countTemp!=NULL){
    if(strcmp(plateNumber,countTemp->plateNumber)==0){ // comparing to plate number
        found =1;
        position = counter;
    }
    countTemp=countTemp->next;
     counter++; //  counter will increase
  }

    if (found==0){ // it is not founded in the list
        printf("\nCar not found\n");
        return 0;
    }

    Car * returnedCar = calloc(1,sizeof(Car)); // allocating the memory

    if (position == 0)
    {
        *carList = temp->next;   
         strcpy(returnedCar->plateNumber,temp->plateNumber);
         returnedCar->mileage = temp->mileage;
         returnedCar->date = temp->date;
         returnedCar->next = NULL;
        free(temp);            
        return returnedCar;
    }
    while(i<position-1){
       temp = temp->next;
      i++;
    }

    next = temp->next->next;
    free(temp->next); 
    temp->next = next; 
    returnedCar->mileage = temp->mileage;
    returnedCar->date = temp->date;
    returnedCar->next = NULL;
    return returnedCar;

}

Car * RentAvaliableCar(Car ** carList){

    int position = 0;
    int i = 0;
    Car *next;
    Car* temp = *carList;
    getchar();
    char returnDate[255];
    printf("Enter The Car's Expected Return Date: ");
    fgets(returnDate,255,stdin);
    returnDate[strlen(returnDate)-1 ] = '\0';
   
    int date = atoi(returnDate);

    position = 0;

    Car * returnedCar = calloc(1,sizeof(Car));

    if (position == 0)
    {
        *carList = temp->next;   
         strcpy(returnedCar->plateNumber,temp->plateNumber); // copied into the plateNumber
         returnedCar->mileage = temp->mileage;
         returnedCar->date = date;
         returnedCar->next = NULL;
        free(temp);            
        return returnedCar;
    }
    while(i<position-1){
       temp = temp->next;
      i++;
    }

    next = temp->next->next;
    free(temp->next); 
    temp->next = next; 
    returnedCar->mileage = temp->mileage;
    returnedCar->date = date; // it will equal to date
    returnedCar->next = NULL;
    return returnedCar;

}

void writeToFile(Car *avaliableRentedCars,Car * rentedCars, Car * inRepairedCar){
    FILE*fp = fopen("CarsList.txt","w");
    Car *temp = avaliableRentedCars;
    while(temp!=NULL){
        if(temp!=NULL){
        fprintf(fp,"%c %s %d %d\n",'A',temp->plateNumber,temp->mileage,temp->date); // writing the variables
      }
      temp=temp->next;

      if(temp==NULL){
        printf("\nOutput successful for Avaliable Rented Cars List!\n");
      }
    }
    temp = rentedCars;
    while(temp!=NULL){
        if(temp!=NULL){
        fprintf(fp,"%c %s %d %d\n",'R',temp->plateNumber,temp->mileage,temp->date);
        }
        temp=temp->next;

        if(temp==NULL){
        printf("\nOutput successful for Rented Cars List!\n");
        }
    }
   temp = inRepairedCar;
   while(temp!=NULL){
    if(temp!=NULL){
    fprintf(fp,"%c %s %d %d\n",'F',temp->plateNumber,temp->mileage,temp->date);
    }
    temp=temp->next;

    if(temp==NULL){
    printf("\nOutput successful for Repaired Cars List!\n");
    }
    }
    fclose(fp);
}

void readFromFile(Car **avaliableRentedCars,Car ** rentedCars, Car ** inRepairedCar){
    FILE*fp = fopen("CarsList.txt","r");  // opening the file 


    char category = 0;

    if(fp == NULL){
        printf("\nNo Values Exist\n");
        return;
    }
    while(!feof(fp)){ // reading the file end of the file
        Car *node = calloc(1,sizeof(Car));
        fscanf(fp,"%c %s %d %d\n",&category,node->plateNumber,&node->mileage,&node->date); // getting the values
        node->next=NULL;
        if(category == 'A'){
            addCarToList(avaliableRentedCars,node);
        }else if(category == 'R'){
            addCarToList(rentedCars,node);
        }else if(category == 'F'){
            addCarToList(inRepairedCar,node);
        }
    }

    fclose(fp);

}

void exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return;
        
    }
    file = fopen(fname,"w");
    fclose(file);
    
}


int main (void) {

	Car * avaliableRentedCars=NULL;
    Car * rentedCars=NULL;
    Car * inRepairedCars=NULL;
    exists("CarsList.txt");
    readFromFile(&avaliableRentedCars,&rentedCars,&inRepairedCars);
    sortMile(&avaliableRentedCars); // sorting according to mile
    sortDate(&rentedCars); // sorting according to rented cars
char input = -1;

do{  // do while loop for the menu
printf("\n");
printf("(1) Add a new car to the available-for-rent list\n");
printf("(2) Add a returned car to the available-for-rent list\n");
printf("(3) Add a returned car to the repair list\n");
printf("(4) Transfer a car from the repair list to the available-for-rent list\n");
printf("(5) Rent the first available car \n");
printf("(6) Print all the lists  \n");
printf("(7) Quit\n");
printf("\n");
         
        printf("Choose a menu option: (1-7) ");
          scanf(" %c", &input);
            if(input>=48&& input<=57){
                int inputInt = input-'0';
                switch (inputInt)
        {
        case 1:
            addCarToList(&avaliableRentedCars,createCar());
            sortMile(&avaliableRentedCars);
            sortDate(&rentedCars);
        break;

        case 2:
            addCarToList(&avaliableRentedCars,DeleteCar(&rentedCars));
            sortMile(&avaliableRentedCars);
            sortDate(&rentedCars);
       

        break;

        case 3:
            addCarToList(&inRepairedCars,DeleteCar(&rentedCars));
            sortMile(&avaliableRentedCars);
            sortDate(&rentedCars);
        

        break;

        case 4: 
        addCarToList(&avaliableRentedCars,TransferCar(&inRepairedCars));
        sortMile(&avaliableRentedCars);
        sortDate(&rentedCars);

        break;

        case 5 :
        addCarToList(&rentedCars,RentAvaliableCar(&avaliableRentedCars));
        sortMile(&avaliableRentedCars);
        sortDate(&rentedCars);
        break;

        case 6:
        displaysAllLists(avaliableRentedCars,rentedCars,inRepairedCars);
        sortMile(&avaliableRentedCars);
        sortDate(&rentedCars);
        break;

        case 7:
        writeToFile(avaliableRentedCars,rentedCars,inRepairedCars);
        printf("The overall Profit Made From this: $%.2f\n",profit);
        return 0;
        break;


        }
            }else{
                printf("\nInvalid input not a number\n");
            }
        
      }
      
      while(input!=7);   // do while loop until we type 7 if we type 7 it is going to be exit the program

    return 0;
    }
