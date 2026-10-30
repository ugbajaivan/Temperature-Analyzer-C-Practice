#include <stdio.h>
#include <stdlib.h>

double highestTemp(double temps[], int size){
    
    double temp = temps[0];
        for(int i=1; i<size; i++){
            if(temps[i]>temp){
                temp = temps[i];
            }
        }

    //printf("Highest temp is %lf\n", temp);

    return temp;
}

double lowestTemp(double temps[], int size){
    
    double temp = temps[0];
        for(int i=1; i<size; i++){
            if(temps[i]<temp){
                temp = temps[i];
            }
        }
    return (temp);
    }

double meanTemp(double temps[], int size){

    double sum = 0;
    for(int i=0; i<size; i++){
        sum += temps[i];
    }

    double avg = sum/size;
    
    return (avg);
}

int countAboveThreshold(double temps[], int size, double threshold){
    int count = 0;

    //printf("Counting...\n");

    for(int i=0; i<size; i++){
        if(temps[i] > threshold){
            count++;
        }
    }
    return (count);
}

double *filterTemps(double temps[], int size, double threshold, int *new_size) {

    // Count temperatures above the threshold
    int count = countAboveThreshold(temps, size, threshold);
    *new_size = count; // Store the number of temps above the threshold into *new_size

    if (count == 0) { // Returning NULL if there are not temps above the threshold
        return NULL;
    }

    // Allocate memory using malloc()
    double *highTemps = malloc(count * sizeof(double));

    if(highTemps == NULL){
        printf("Memory Allocation Failed!");
        *new_size = 0; //Preventing the main() function from assuming the array contains valid values
        return NULL;
    }

    //Adding the higher temps a new array
    int j = 0;
    for(int i=0; i<size; i++){
        if(temps[i]>threshold){
            highTemps[j] = temps[i];
            j++;
        }
    }

    // Step 5: Return the new array
    return(highTemps);
}

void swap(double *a, double *b){
    /*Function to swap two values in an array by dereferencing */

    double temp = *a;
    *a = *b;
    *b = temp;
    return;
}

double orderTemps(double temps[], int size){ // Ordering the temps from highest to lowest using bubble sort

    for(int i=0; i < size-1; i++){
        for(int j=0; j < size - 1 - i; j++){
            if(temps[j] < temps[j+1]){
                swap(&temps[j], &temps[j+1]);
            }
        }
    }
}

void writeTemps(const char *filename, double temps[], int size) { // int size passed into the function will be the new_size

    // Open the file in write mode
    FILE *fptr = fopen(filename, "w");

    // Check if the file opened successfully
    if(fptr == NULL){
        printf("File was not opened successfully");
        return;
    }

    // Loop through the array
    for(int i=0; i<size; i++){
        fprintf(fptr,"%.2lf\n" , temps[i]); // 4. Write each temperature using fprintf()
    }

    // Close the file
    fclose(fptr);
}


int main(void){

    // Declaring Variables without initializing their values
    double highest;
    double lowest;
    double mean;
    double threshold;
    int numAboveThreshold;
    int new_size;

    double temps[] = {18.5, 22.3, 19.7, 27.1, 24.6};
    int size = sizeof(temps) / sizeof(temps[0]);// Using this format allows me to find the number of items in the array
                                                // by using the size(temps) & sizeof(temps[0]) cuz all same size

    highest = highestTemp(temps, size);     //Highest Temp in the txt file
    lowest = lowestTemp(temps, size);       //Lowest Temp in the txt file
    mean = meanTemp(temps, size);           //Mean Temp in the txt file

    printf("%lf\n", highest);
    printf("%lf\n", lowest);
    printf("%lf\n", mean);


    printf("Enter a temp threshold: ");
    scanf("%lf", &threshold);
    numAboveThreshold = countAboveThreshold(temps, size, threshold);
    printf("There are %d temperatures above the threshold\n", numAboveThreshold);

    new_size = 0;
    double *highTemps = filterTemps(temps, size, threshold, &new_size);

    if(new_size == 0 && highTemps == NULL){
        printf("Memory Allocation Failed!");
        return 1;
    }

    orderTemps(highTemps, size);

    /* Listing the temps above the threshold, uncomment if you want to see the values
    for(int i=0; i<new_size; i++){
        printf("%.2lf\n", highTemps[i]);
    }
    */

    // Write the temps into a new file
    if (new_size > 0) {
        writeTemps("high_temps.txt", highTemps, new_size);
    } else {
        printf("No temperatures were above the threshold.\n");
    }

    free(highTemps);

    return 0;
}