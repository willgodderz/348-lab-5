#include <stdio.h>

#define MONTHS 12

// declaires functions types and parameters
void monthly_sales_report(float sales[], const char *months[]);
void sales_summary_report(float sales[], const char *months[]);
void six_month_moving_average_report(float sales[], const char *months[]);
void sales_report_high_to_low(float sales[], const char *months[]);

int main() {
    //opens examples.txt file
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) { //checks if file was opened right
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Array of months for output
    const char *months[MONTHS] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

    // Array to store sales data
    float sales[MONTHS];
    
    // Reads sales data into sales array
    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%f", &sales[i]);
    }

    fclose(file); //closes file

    printf("Monthly Sales Report for 2024\n");
    monthly_sales_report(sales, months); //calls monthly slaes report
    printf("\nSales Summary Report:\n");
    sales_summary_report(sales, months); //calls sales summary
    printf("\nSix-Month Moving Average Report:\n");
    six_month_moving_average_report(sales, months); //calls moving average report
    printf("\nSales Report (Highest to Lowest):\n");
    sales_report_high_to_low(sales, months); //calls high to low

    return 0;
}

//generates the Monthly Sales Report
void monthly_sales_report(float sales[], const char *months[]) {
    printf("%-10s %10s\n", "Month", "Sales"); //prints header
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s %10.2f\n", months[i], sales[i]); //prints each month and sale
    }
}

//generates the Sales Summary Report
void sales_summary_report(float sales[], const char *months[]) {
    float min_sales = sales[0], max_sales = sales[0], total_sales = 0; //inits min and max and total sales
    int min_index = 0, max_index = 0;
//loops through sales data
    for (int i = 0; i < MONTHS; i++) {
        total_sales += sales[i];
        if (sales[i] < min_sales) {
            min_sales = sales[i];
            min_index = i;
        }
        if (sales[i] > max_sales) {
            max_sales = sales[i];
            max_index = i;
        }
    }

    float average_sales = total_sales / MONTHS; //calcs average sale

    printf("Minimum sales: %.2f (%s)\n", min_sales, months[min_index]);
    printf("Maximum sales: %.2f (%s)\n", max_sales, months[max_index]);
    printf("Average sales: %.2f\n", average_sales);
}

//generates Six-Month Moving Average Report
void six_month_moving_average_report(float sales[], const char *months[]) {
    //loops to calculate moving average for each 6 months
    for (int i = 0; i <= MONTHS - 6; i++) {
        float sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        float average = sum / 6; //calculates the current window
        printf("%s-%s: %.2f\n", months[i], months[i + 5], average);
    }
}

// generates the Sales Report highest to lowest
void sales_report_high_to_low(float sales[], const char *months[]) {
    // Create a copy
    float sorted_sales[MONTHS];
    const char *sorted_months[MONTHS];

    for (int i = 0; i < MONTHS; i++) {
        sorted_sales[i] = sales[i];
        sorted_months[i] = months[i];
    }

    //Sort the sales from high to low
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = i + 1; j < MONTHS; j++) {
            if (sorted_sales[i] < sorted_sales[j]) {
                // Swap sales
                float temp_sales = sorted_sales[i];
                sorted_sales[i] = sorted_sales[j];
                sorted_sales[j] = temp_sales;

                //swap corresponding months
                const char *temp_month = sorted_months[i];
                sorted_months[i] = sorted_months[j];
                sorted_months[j] = temp_month;
            }
        }
    }

    //Prints sorted sales 
    printf("%-10s %10s\n", "Month", "Sales"); //header
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s %10.2f\n", sorted_months[i], sorted_sales[i]);
    }
}
