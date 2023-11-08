#include <stdio.h>
#include <stdlib.h>

//taxes
double CIF,R,roadTolls,borderFees,parkingFees,seatingCapacityFees,grossWeightFees,engineCapacityFees;
double ID = 0;//0.25 * CIF;
double VAT = 0;//0.18 * CIF;
double WHT = 0;//0.06 * CIF;
double APS = 300000;
double DPS = 700000;
double IL = 150000;
double SD = 35000;
double FF = 20000;
double ED = 200000;

//car specifications
int release_year,import_mthd,days_in_bond,gross_weight,seating_capacity,engine_capacity,vehicle,plate_type,car_age;

//Get Car Type
void importVehicle(){

    printf(" What Vehicle are you trying to import\n\n");
    printf("  1. AMBULANCE\n  2. ESTATE\n  3. SEDAN\n  4. SUV\n  5. TRAILER\n  6. OTHER\n\n ");
    scanf("%d", &vehicle);

    if(vehicle > 6 || vehicle < 1){
        printf("Please choose the correct option\n\n");
        importVehicle();
    }

}

//Get Car Plate Type to define registration
void get_plate_type(){

    printf(" Choose Registration Plate type\n\n");
    printf("  1. APS\n  2. DPS\n ");
    scanf("%d", &plate_type);

    if(plate_type > 2 || plate_type < 1){
        printf("Please choose the right option\n");
        get_plate_type();
    }

}

//Get Registration
void calcRegistration(){
//R - Registration

    if(vehicle == 1 || vehicle == 3){
        R = DPS;
    }else if(vehicle == 4){
        R = APS;
    }else{
        get_plate_type();
        R = plate_type == 1 ? APS : DPS;
    }




}

//calculate border or troll fees
void calcBorderTollFees(){

    printf(" How was the Vehicle imported into the Country\n  1. Delivered on a carrier bed vehicle\n  2. Driven into the country\n ");
    scanf("%d", &import_mthd);

     if(import_mthd > 2 || import_mthd < 1){
        printf("Please choose the right option\n");
        calcBorderTollFees();
    }

    if(import_mthd == 1){
        roadTolls = 0.005 * CIF;
        borderFees = 0.015 * CIF;
    }else {
        roadTolls = 0;
        borderFees = 0.015 * CIF;
    }

}

//parking fee
void calcParkingFee(){
    parkingFees = (double) days_in_bond * 15000;
}

//get Car age
int calcCarAge(){
    return 2023 - release_year;
}

//vehicle info
void getVehicleInfo(vehicle){
    printf("PLEASE ENTER VEHICLE DETAILS\n\n");

    //get the year of manufacture
    printf("\nYear of Manufacture: ");
    scanf("%d", &release_year);

    //get the days spent in bond
    printf("\nDays in Bond: ");
    scanf("%d", &days_in_bond);

    //get the Cost of Insurance Freight (CIF)
    printf("\nCost of Insurance Freight (CIF) value: ");
    scanf("%lf", &CIF);

    if(vehicle != 1){
         printf("\nGross Weight in tons: ");
        scanf("%d", &gross_weight);

        //get the year of manufacture
        printf("\nEngine Capacity(cc): ");
        scanf("%d", &engine_capacity);

        //get the days spent in bond
        printf("\nSeating Capacity: ");
        scanf("%d", &seating_capacity);
    }

}

//print vehicle specifications
void printVehicleSpecification(char name[60]){
    printf(" VEHICLE SPECIFICATIONS\n");
    printf("  Vehicle name: %s\n",name);
    printf("  The Cost Insurance Freight: %lf\n",CIF);
    printf("  Manufacture Year: %d\n",release_year);
    printf("  Days Spent in Bond: %d\n",days_in_bond);

     if(plate_type == 1){
        printf(" Number Plate System: Analog Plate System\n");
    }else{
        printf(" Number Plate System: Digital Plate System\n");
    }

    if(import_mthd == 1){
        printf(" Mode of transportation: Carrier bed vehicle\n");
    }else{
        printf(" Mode of transportation: Driven into the country\n");
    }

    if(vehicle != 1){
        printf("Gross Weight: %d\n", gross_weight);
        printf("Engine Capacity: %d\n",engine_capacity);
        printf("Seating Capacity: %d people\n", seating_capacity);
    }

}

void printVehicleTaxInfo(){


    printf(" THE VEHICLE WILL PAY THE FOLLOWING TAXES\n");

    printf("Import Duty: %lf\n",ID);
    printf("Value Added Tax: %lf\n",VAT);
    printf("Withholding Tax: %lf\n",WHT);
    printf("Infrastructure Levy: %lf\n",IL);
    printf("Stamp Duty: %lf\n",SD);
    printf("Form Fees: %lf\n",FF);
    printf("Excise Duty: %lf\n",ED);
    printf("Registration: %lf\n",R);
    printf("Road Tolls: %lf\n",roadTolls);
    printf("Border Fees: %lf\n",borderFees);
    printf("Parking Fees: %lf\n",parkingFees);

    if( vehicle != 1){
        printf("Seating Capacity Fees: %lf\n",seatingCapacityFees);
        printf("Gross weight Fees: %lf\n",grossWeightFees);
        printf("Engine Capacity Fees: %lf\n",engineCapacityFees);
    }
}

//compute the vehicle taxes
void UGTaxSystem(){

    getVehicleInfo(vehicle);
    calcParkingFee();
    calcRegistration();
    calcBorderTollFees();
    calcCarAge();

    if(car_age > 10){
        IL = 0.15 * CIF;
    }


    switch(vehicle){
        case 1:
            ID = VAT = WHT = 0;
           
            printVehicleSpecification("Ambulance");
            printVehicleTaxInfo();

        break;
        case 2:
           ID = 0.25 * CIF;
           VAT = 0.18 * CIF;
           WHT = 0.06 * CIF;
            
           for(car_age = 1, car_age < 5, car_age++){
                IL = IL + 0.01*CIF;
           }

           for(car_age = 5, car_age <= 10, car_age++){
                IL = IL + 0.05*CIF;
           }

           if(seating_capacity > 5){
                seatingCapacityFees = (double) 250000*seating_capacity;
           }

           if(gross_weight > 2000){
                grossWeightFees = 0.1 * CIF;
           }else if(gross_weight < 1500){
                grossWeightFees = 0.02 * CIF;
           }else{
                grossWeightFees = 0.05 * CIF;
           }

           if(engine_capacity > 1800){
                engineCapacityFees = 0.05 * CIF;
           }else{
                engineCapacityFees = 0.025 * CIF
           }

            printVehicleSpecification("Estate");
            printVehicleTaxInfo();

    }
}




int main()
{

    printf("WELCOME TO THE URA IMPORT TAX SYSTEM\n\n");
    importVehicle();
    UGTaxSystem();
    return 0;
}
