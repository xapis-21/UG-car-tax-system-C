#include <stdio.h>
#include <stdlib.h>

int importVehicle(){
    int vehicle;
    printf("What Vehicle are you trying to import\n");
    printf(" 1. AMBULANCE\n 2. ESTATE\n 3. SEDAN\n 4. SUV\n 5. TRAILER\n 6. OTHER\n ");
    scanf("%d", &vehicle);

    return vehicle;

}

int main()
{

    printf("WELCOME TO THE URA IMPORT TAX SYSTEM\n\n");
    printf("%d",importVehicle());
    return 0;
}
