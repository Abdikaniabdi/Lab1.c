################################
#
# Program Name: Parts Record Manager C program
#
# Author: Abdikani Abdi
#
################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARTS 100
#define MAX_NAME_LENGTH 50
#define MAX_METRIC_LENGTH 10

// Define a struct that represent a part record
typedef struct { 
    int partNum; // part name
    char partName[MAX_NAME_LENGTH]; // name of part
    float partSize; // size of part
    char partSizeMetric[MAX_METRIC_LENGTH]; // metric unit of part size
    float partCost; // cost of part
} PartRecord;

// Function to add a new part record
PartRecord addRecord() {
    PartRecord newPart;

    printf("Adding Part Record\n\n");

    printf("Enter Part Number: "); 
    scanf("%d", &newPart.partNum); // input ot get part number

    printf("Enter Part Name: ");
    scanf("%s", newPart.partName); // input to get part name

    printf("Enter Part Size: ");
    scanf("%f", &newPart.partSize); // input to get part size

    printf("Enter Part Size Metric (ex: lbs, kg, inches): ");
    scanf("%s", newPart.partSizeMetric); // input to get metric unit

    printf("Enter Part Cost: ");
    scanf("%f", &newPart.partCost); //input to get part cost

    return newPart; // return to part record
}

// Function to print all part records
void printRecords(PartRecord partsRecordList[], int count) {
    printf("\n\nPrint out list of parts in database: \n\n"); //// keeps track of the number of records

    for (int i = 0; i < count; i++) {
        printf("Part Number: %d\n", partsRecordList[i].partNum);
        printf("Part Name: %s\n", partsRecordList[i].partName);
        printf("Part Size: %.2f\n", partsRecordList[i].partSize);
        printf("Part Metric: %s\n", partsRecordList[i].partSizeMetric);
        printf("Part Cost: %.2f\n", partsRecordList[i].partCost);
        printf("\n\n");
    }
}

int main() {
    PartRecord partsRecordList[MAX_PARTS]; // Stores records
    int recordCount = 0; //Keeps track of the number of records

    // Add a test record
    partsRecordList[0].partNum = 1;
    strcpy(partsRecordList[0].partName, "wheel");
    partsRecordList[0].partSize = 15;
    strcpy(partsRecordList[0].partSizeMetric, "inches");
    partsRecordList[0].partCost = 150;
    recordCount++;

    while (1) {
        printf("\nParts Management System\n");
        printf("1. Print all records\n");
        printf("2. Add record\n");
        printf("3. Delete the last record\n");
        printf("4. Print number of records\n");
        printf("5. Print database size\n");
        printf("6. Print number of changes\n");
        printf("7. Exit\n");

        int selection;
        printf("\nPlease enter your selection (1-7): ");
        scanf("%d", &selection); // Get user selection

        switch (selection) {
            case 1:
                printRecords(partsRecordList, recordCount); // call function to print records
                break;

            case 2:
                if (recordCount < MAX_PARTS) { // checks if there is space to add new record
                    partsRecordList[recordCount] = addRecord(); //Add new part record
                    recordCount++; // Increase record count
                } else {
                    printf("Database is full. Cannot add more records.\n");
                }
                break;

            case 3:
                if (recordCount > 0) {
                    recordCount--; // Reduce record count by one which deletes the last record
                    printf("Last record deleted.\n");
                } else {
                    printf("No records to delete.\n");
                }
                break;

            case 4:
                printf("\n\nNumber of parts records is: %d\n", recordCount);
                break; //// Print total number of records

            case 5:
                printf("\n\nSize of parts record database is: %lu bytes\n", recordCount * sizeof(PartRecord));
                break; // Print memory size of stored records

            case 7:
                printf("\n\nThank you for using the Parts Management System\n");
                return 0; // // after exit the program

            default:
                printf("Invalid selection. Please try again.\n"); // to handle incorrect input
                break;
        }
    }

    return 0;
}
