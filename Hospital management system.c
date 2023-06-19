#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int AdhesiveTape=1000,Gloves=1500,scissors=500,pins=2000,tweezers=750,dentalkit=200,syringes=3000,bandages=3000,thermometer=1000,cotton=4000,medicines=4000,mask=2000,plaster=500;

struct patient
{
    char firstpatientname[100];
    char lastpatientname[100];
    char patientaddress[100];
    char patientemail[100];
    char patientphone[10];
    char patientmarital[100];
    char patientoccupation[100];
    int patientage;
    int patientac;
    int patientsex;
    int patientfamily;
    int patientemergency;
    struct patient* next;
};
int start=0;
struct patient* current=NULL;
struct patient* previous=NULL;
struct patient* emergencylast=NULL;
struct patient* normallast=NULL;
struct patient* emergencyhead=NULL;
struct patient* normalhead=NULL;

void PatientMenu();
void PatientInfo();
void StaffSignup();
void StaffLogin();
void PatientLogin();
void PatientSignUp();
void PatientForm();
void StaffMenu();
void Help();
void StaffSalary();
void StockInfo();
void HospitalInfo();
void AddStock();
void DoctorInfo();
void DiseaseInfo();
void PatientSearch();
void Checkout();
void Start();
void PatientL();
void StaffL();

int main()
{
    printf("     ++++++    \n");
    printf("     ++++++    \n");
    printf("     ++++++    \n");
    printf("++++++++++++++++\n");
    printf("++++++++++++++++\n");
    printf("++++++++++++++++\n");
    printf("     ++++++    \n");
    printf("     ++++++    \n");
    printf("     ++++++    \n");
    Start();
}
void Start()
{
    do
    {
        printf("Choose From The Following: \n");
        printf("1. Patient\n");
        printf("2. Staff\n");
        printf("3. Exit\n");
        scanf("%d",&start);
        if(start==1)
        PatientMenu();
        else if(start==2)
        StaffMenu();
        else if(start==3)
        exit(0);
        else
        printf("Invalid Choice, Enter again");
    }while(start!=1 && start!=2 && start!=3);
}

void PatientLogin()
{
    int pm;
    do
    {
        printf("Choose From The Following: \n");
        printf("1. See Patient Form Info\n");
        printf("2. See Problems Solved DiseasesInfo\n");
        printf("3. See Hospital Doctors info\n");
        printf("4. About Hospital\n");
        printf("5. Checkout\n");
        printf("6. Help\n");
        printf("7. Logout and Main Menu\n");
        printf("8. Exit\n");
        scanf("%d",&pm);
       
        switch(pm)
        {
            case 1:
            {
                PatientSearch();
                break;
            }
            case 2:
            {
                DiseaseInfo();
                break;
            }
            case 3:
            {
                DoctorInfo();
                break;
            } 
            case 4:
            {
                HospitalInfo();
                break;
            }
            case 5:
            {
                Checkout();
                break;
            }
            case 6:
            {
                Help();
                break;
            }
            case 7:
            {
                Start();
                break;
            }
            case 8: exit(0);
            default: printf("Invalid Option, Choose Again!\n");
        }
    }while(pm<1 || pm>8);
}
void PatientMenu()
{
    int account;
    do
    {
    printf("Choose From The Following: \n");
    printf("1. Login (Existing Patient)\n");
    printf("2. Signup (New Patient)\n");
    scanf("%d",&account);
    if(account!=1 && account!=2)
    printf("Invalid Option, Choose Again\n");
    }while(account!=1 && account!=2);
    if(account==1)
    PatientL();
    else
    PatientSignUp();
    PatientLogin();
}

void PatientInfo()
{
    if(emergencyhead==NULL && normalhead==NULL)
    {
        printf("There Are No Patients\n");
    }
    else
    {
    current=emergencyhead;
    previous=NULL;
    while(current!=NULL)
    {
        printf("Name: %s %s",current->firstpatientname,current->lastpatientname);
        printf("\n");
        printf("Address: %s",current->patientaddress);
        printf("\n");
        printf("Contact Number: %s",current->patientphone);
        printf("\n");
        printf("Email: %s",current->patientemail);
        printf("\n");
        printf("Marital Staus: %s",current->patientmarital);
        printf("\n");
        printf("Occupation: %s",current->patientoccupation);
        printf("\n");
        printf("Age: %d",current->patientage);
        printf("\n");
        if(current->patientsex==1)
        printf("Gender: Male");
        else if(current->patientsex==2)
        printf("Gender: Female");
        else
        printf("Gender: Others");
        printf("\n");
        printf("Family Members: %d",current->patientfamily);
        printf("\n");
        if(current->patientac==1)
        printf("AC Room: Yes");
        else
        printf("AC Room: No");
        printf("\n");
        printf("\n");
        current=current->next;
    }
    current=normalhead;
    while(current!=NULL)
    {
        printf("Name: %s %s",current->firstpatientname,current->lastpatientname);
        printf("\n");
        printf("Address: %s",current->patientaddress);
        printf("\n");
        printf("Contact Number: %s",current->patientphone);
        printf("\n");
        printf("Email: %s",current->patientemail);
        printf("\n");
        printf("Marital Staus: %s",current->patientmarital);
        printf("\n");
        printf("Occupation: %s",current->patientoccupation);
        printf("\n");
        printf("Age: %d",current->patientage);
        printf("\n");
        if(current->patientsex==1)
        printf("Gender: Male");
        else if(current->patientsex==2)
        printf("Gender: Female");
        else
        printf("Gender: Others");
        printf("\n");
        printf("Family Members: %d",current->patientfamily);
        printf("\n");
        if(current->patientac==1)
        printf("AC Room: Yes");
        else
        printf("AC Room: No");
        printf("\n");
        printf("\n");
        current=current->next;
    }
    }
    StaffLogin();
}

void StaffSignup()
{
    printf("You have Chose For New Application\n");
    char newstaffname[100];
    int newstaffage;
    char newstaffaddress[100];
    char newstaffphone[10];
    char newstaffmail[100];
    int pastyearexp;
    char newstaffdegree[100];
   
    printf("Enter Your Name: \n");
    scanf("%s",newstaffname);
    printf("Enter Your Age: \n");
    scanf("%d",&newstaffage);
    printf("Enter Your Address: \n");
    scanf("%s",newstaffaddress);
    printf("Enter Your Phone Number: \n");
    scanf("%s",newstaffphone);
    printf("Enter Your Mail ID: \n");
    scanf("%s",newstaffmail);
    printf("Enter Your Experience in Years: \n");
    scanf("%d",&pastyearexp);
    printf("Enter Your Degrees: \n");
    scanf("%s",newstaffdegree);
    printf("Thank You For Submitting Your Application, You Will Recieve The Update Via Ypur Contact Information\n");
    int ss;
    do
    {
        printf("Choose From The Following: \n");
        printf("1. About Hospital\n");
        printf("2. Help\n");
        printf("3. Exit\n");
        scanf("%d",&ss);
       
        switch(ss)
        {
            case 1: HospitalInfo();
            case 2: Help();
            case 3: exit(0);
            default: printf("Invalid Option, Choose Again!\n");
        }
    }while(ss<1 || ss>3);
   Start();
}

void StaffL()
{
    int staffloginpass,staffsavedloginpass=12345;
	char staffloginusername[20];
	printf("You Have Chose To Log In\n");
	printf("Enter Your Username:\n");
    scanf("%s",staffloginusername);
	do
	{
	    printf("Please Enter Your Password:\n");
	    scanf("%d",&staffloginpass);
	    if(staffloginpass==staffsavedloginpass)
	    printf("You Have Been Logged In\n");
    	else
	    printf("Wrong Password,You Have Not Been Logged In,Try Again\n");
    }while(staffloginpass!=staffsavedloginpass);
    StaffLogin();
}
void StaffLogin()
{
    int sm;
    do
    {
        printf("Choose From The Following: \n");
        printf("1. Existing Patients Info\n");
        printf("2. Doctor Info\n");
        printf("3. About Hospital\n");
        printf("4. Check Current Stock Info\n");
        printf("5. Renew Stock Request\n");
        printf("6. Check Current Salary\n");
        printf("7. Help\n");
        printf("8. Logout and Main Menu\n");
        printf("8.Exit\n");
        scanf("%d",&sm);
       
        switch(sm)
        {
            case 1:
            {
                PatientInfo();
                break;
            }
            case 2:
            {
                DoctorInfo();
                break;
            }
            case 3:
            {
                HospitalInfo();
                break;
            }
            case 4:
            {
                StockInfo();
                break;
            }
            case 5:
            {
                AddStock();
                break;
            }
            case 6:
            {
                StaffSalary();
                break;
            }
            case 7:
            {
                Help();
                break;
            }
            case 8:
            {
                Start();
                break;
            }
            case 9: exit(0);
            default: printf("Invalid Option, Choose Again!\n");
        }
    }while(sm>8 || sm<1);
}

void PatientL()
{
    int patientloginpass,patientsavedloginpass=12345;
	char patientloginusername[20];
	printf("You Have Chose To Log In\n");
	printf("Enter Your Username:\n");
    scanf("%s",patientloginusername);
	do
	{
	    printf("Please Enter Your Password:\n");
	    scanf("%d",&patientloginpass);
	    if(patientloginpass==patientsavedloginpass)
        printf("You Have Been Logged In\n");
        else
        printf("Wrong Password,You Have Not Been Logged In,Try Again\n");
	}while(patientloginpass!=patientsavedloginpass);
	PatientLogin();
}

void PatientSignUp()
{
    char patientsignupfirstname[20];
    char patientsignuplastname[30];
    char patientsignupemail[50];
    int patientconfirmpass;
    char patientsignuppass[20];
    char patientsignupcpass[20];
    printf("You Have Chose To Sign Up\n");
    printf("Follow The Following Steps For A New Patient\n");
    printf("Enter Your First Name\n");
    scanf("%s",patientsignupfirstname);
    printf("Enter Your Last Name\n");
    scanf("%s",patientsignuplastname);
    printf("Enter Your Email\n");
    scanf("%s",patientsignupemail);
    do
    {
        printf("Choose Your Password\n");
        scanf("%s",patientsignuppass); 
        printf("Confirm Your Password\n");
        scanf("%s",patientsignupcpass);
        patientconfirmpass = strcmp(patientsignuppass, patientsignupcpass);
        if(patientconfirmpass == 0)
	    printf("Thanks For Signing Up\n");
        else
	    printf("Your Confirmed Password Does Not Match The Orignal Password, Try Again\n");
    }while (patientconfirmpass != 0);
    PatientForm();
}

void PatientForm()
{
    struct patient* new=(struct patient*)malloc(sizeof(struct patient));
    printf("Enter First Name Of Patient:");
    scanf("%s",new->firstpatientname);
    printf("Enter Last Name Of Patient:");
    scanf("%s",new->lastpatientname);
    printf("Enter Patient Adress:");
    scanf("%s",new->patientaddress);
    printf("Enter Patient Phone Number:");
    scanf("%s",new->patientphone);
    printf("Enter Patient Email:");
    scanf("%s",new->patientemail);
    printf("Enter Patient Marital Status:");
    scanf("%s",new->patientmarital);
    printf("Enter Patient Occupation:");
    scanf("%s",new->patientoccupation);
    printf("Enter Patient Age:");
    scanf("%d",&new->patientage);
    printf("Enter Patient Gender,1 for Male,2 for Female,3 for Others:");
    scanf("%d",&new->patientsex);
    printf("Enter Number of Family Members With Patient:");
    scanf("%d",&new->patientfamily);
    printf("Is It A Emergency? 1 For Yes, 2 For NO:");
    scanf("%d",&new->patientemergency);
    printf("Do You Want AC In Your Room? 1 For Yes, 2 For NO:");
    scanf("%d",&new->patientac);
    
    new->next=NULL;
    
    if(new->patientemergency==1)
    {
        if(emergencyhead==NULL)
        {
            emergencyhead=new;
        }
        else
        {
            current=emergencyhead;
            previous=NULL;
            while(current!=NULL)
            {
                previous=current;
                current=current->next;
            }
            
            previous->next=new;
        }
    }
    else
    {
        if(normalhead==NULL)
        {
            normalhead=new;
        }
        else
        {
            current=normalhead;
            previous=NULL;
            while(current!=NULL)
            {
                previous=current;
                current=current->next;
            }
            
            previous->next=new;
        }
    }
    PatientLogin();
}

void StaffMenu()
{
    int account;
    do
    {
    printf("Choose From The Following: \n");
    printf("1. Login (Existing Staff)\n");
    printf("2. Signup (New Staff)\n");
    scanf("%d",&account);
    if(account!=1 && account!=2)
    printf("Invalid Option, Choose Again\n");
    }while(account!=1 && account!=2);
    if(account==1)
    StaffL();
    else
    StaffSignup();
}

void Help()
{
    char helpemail[30];
	int helpchoice,helpnumber,faqchoice;
	printf("You have selected the Help Option\n");
	do
	{
	    printf("How can we Help you:\n 1.Call from our Customer Help Service \n 2.Mail ID \n 3.Call Us \n 4.FAQ's\n");
		printf("Please Enter your Choice\n");
		scanf("%d",&helpchoice);
		if(helpchoice==1)
		{
			printf("You have selected the Call Help option\n");	 
			printf("Please Enter your Contact Number\n");
			scanf("%d",&helpnumber);
			printf("Our Customer Help Service Department would be contacting you in a Short Time\n");
		}
		else if(helpchoice==2)
		{
		    printf("You have selected the get Help through Mail option\n");
		    printf("Please provide us your Email ID\n");
	    	scanf("%s",helpemail);
		    printf("We will be contacting you soon\n");
		}
		else if(helpchoice==3)
	    printf("This is our Help Line Number\n You can Contact us here:\n 1800 10 8010\n");
	    else if(helpchoice==4)
		{
		    do
			{
			    printf("You have selected the FAQ Option\n");
			    printf("\n");
			    printf("1. How can I schedule my appointments?\n");
			    printf("2. What are the payment modes in this hospital? \n");
			    printf("3. Will I be allowed to have visitors during my treatment?\n");
		        printf("4. Am I allowed to keep my valuables during the time I am admitted?\n");
	     	    printf("5. What is my period of recovery at hospital?\n");
			    printf("6. Will my info be shared with other health care professionals in the ward?\n");
			    printf("7. Are the doctors and surgens in your hospital licenced and credentialed?\n");
			    printf("8. Where do I call to find out the condition of a patient in the hospital?\n");
			    printf("9. What are the visiting hours for patients family and friends?\n");
			    printf("10. Where can i pay my bill\n");
			    printf("Enter the Question number which specifies your Problem\n");
			    printf("If your Question does not lie in these please feel free to Contact us through Other Help Methods.\n");
                scanf("%d",&faqchoice);
                switch(faqchoice)
                {   
                    case 1: printf("Talk with The receptionist to fix a Time. \n"); break;
                    case 2: printf("All Payment Modes are available \n"); break;
                    case 3: printf("Yes upto 3 people at a time are available at a time\n"); break;
                    case 4: printf("Yes, You will be allowed to keep your valueable in your room \n"); break;
                    case 5: printf("Recovery period usuaaly depends on your disease\n"); break;
                    case 6: printf("Yes.\n"); break;
                    case 7: printf("Yes highy Trained Proffessionals\n"); break;
                    case 8: printf("At the reception you can obtain all important Information\n"); break;
                    case 9: printf("You can Visit the patient during 9am to 9pm\n"); break;
                    case 10: printf("At the checkout center\n"); break;
                    default: printf("Enter A Valid Choice!\n");
                    
                }
			}while(faqchoice<1 && faqchoice>10);
		}
	    else
	    printf("Please Enter a Valid Choice\n");
	}while(helpchoice!=1 && helpchoice!=2 && helpchoice!=3 && helpchoice!=4);
	if(start==1)
	PatientLogin();
	else
	StaffLogin();
}

void StaffSalary()
{
    int desig;
    do
    {
        printf("Enter Your Designation:\n");
        printf("1. Specialist(Doctor)\n");
        printf("2. General Doctor\n");
        printf("3. Nurse\n");
        printf("4. Janitor\n");
        printf("5. Receptionist\n");
        printf("6. Pharmacist\n");
        printf("7. Security\n");
        scanf("%d",&desig);
        
        switch(desig)
    {
        case 1: printf("You Are Specialist Doctor\n Your Salary Is 4Lakhs\n"); break;
        case 2: printf("You Are General Doctor\n Your Salary Is 2Lakhs\n"); break;
        case 3: printf("You Are Nurse\n Your Salary Is 75k\n"); break;
        case 4: printf("You Are Janitor\n Your Salary Is 15k\n"); break;
        case 5: printf("You Are Receptionist\n Your Salary Is 30k\n"); break;
        case 6: printf("You Are Pharmacist\n Your Salary Is 40k\n"); break;
        case 7: printf("You Are in Security\n Your Salary Is 10k\n"); break;
        default: printf("Invalid Option,Choose Again\n"); break;
    }
    }while(desig<1 && desig>7);
    StaffLogin();
}

void StockInfo()
{
    
    printf("The Current Stock Consists: \n");
    printf("AdhesiveTape=%d\n",AdhesiveTape);
    printf("Gloves=%d\n",Gloves);
    printf("Scissors=%d\n",scissors);
    printf("Pins=%d\n",pins);
    printf("Tweezers=%d\n",tweezers);
    printf("Dentalkit=%d\n",dentalkit);
    printf("Syringes=%d\n",syringes);
    printf("Bandages=%d\n",bandages);
    printf("Thermometer=%d\n",thermometer);
    printf("Cotton=%d\n",cotton);
    printf("Medicines=%d\n",medicines);
    printf("Masks=%d\n",mask);
    printf("Plasters=%d\n",plaster);
    StaffLogin();
}

void HospitalInfo()
{
    printf("The Hospital is a multi/super speciality hospital located at the prime location of Vaishnodevi Circle, SG Road, Ahmedabad; with state-of-the-art facilities & treatments at an affordable cost, encompassing wide spectrum of accurate diagnostics and elegant therapeutics created on the philosophical edifice of patient and ethical centricity ensuring humanistic dispensation.\n");
    printf("Wea Are Proud to have some of the most eminent and experienced doctors of the world who are authorities in their respective fields of specialisation. We have the top 10 surgeons in India who are well experienced in performing all types of critical surgeries.\n");
    if(start==1)
    PatientLogin();
    else
    StaffLogin();
}

void AddStock()
{
    printf("Enter Each Quantity You Want To Add\n");
    int add;
    printf("AdhesiveTape=\n");
    scanf("%d",&add);
    AdhesiveTape=AdhesiveTape+add;
    printf("Gloves=\n");
    scanf("%d",&add);
    Gloves+=add;
    printf("Scissors=\n");
    scanf("%d",&add);
    scissors+=add;
    printf("Pins=\n");
    scanf("%d",&add);
    pins+=add;
    printf("Tweezers=\n");
    scanf("%d",&add);
    tweezers+=add;
    printf("Dentalkit=\n");
    scanf("%d",&add);
    dentalkit+=add;
    printf("Syringes=\n");
    scanf("%d",&add);
    syringes+=add;
    printf("Bandages=\n");
    scanf("%d",&add);
    bandages+=add;
    printf("Thermometer=\n");
    scanf("%d",&add);
    thermometer+=add;
    printf("Cotton=\n");
    scanf("%d",&add);
    cotton+=add;
    printf("Medicines=\n");
    scanf("%d",&add);
    medicines+=add;
    printf("Masks=\n");
    scanf("%d",&add);
    mask+=add;
    printf("Plasters=\n");
    scanf("%d",&add);
    plaster+=add;
    StaffLogin();
}

void DoctorInfo()
{
    printf("The Hospital Consists The Following Doctors\n");
    printf("**********\n");
    printf("Dr. Rajesh Khanna\n");
    printf("42 Years Old\n");
    printf("98983456789");
    printf("General Doctor\n");
    printf("\n");
    printf("**********\n");
    printf("Dr. Sejal Bhatt");
    printf("40 Years Old\n");
    printf("98981234567\n");
    printf("Gynaecologist\n");
    printf("\n");
    printf("**********\n");
    printf("Dr. Ramesh Bhatt");
    printf("40 Years Old\n");
    printf("98981234567\n");
    printf("Dermatologist\n");
    printf("\n");
    printf("**********\n");
    printf("Dr. Shyam Lal");
    printf("29 Years Old\n");
    printf("98981234567\n");
    printf("Specialist\n");
    printf("\n");
    printf("**********\n");
    printf("Dr. Ram Lal");
    printf("29 Years Old\n");
    printf("98981234567\n");
    printf("Orthopedic\n");
    if(start==1)
    PatientLogin();
    else
    StaffLogin();
}

void DiseaseInfo()
{
    printf("Common Diseases:\n");
    printf("Allergies.\n");
    printf("Colds and Flu.\n");
    printf("Conjunctivitis (pink eye)\n");
    printf("Diarrhea.\n");
    printf("Headaches.\n");
    printf("Mononucleosis.\n");
    printf("Stomach Aches.\n");
    printf("Malaria.\n");
    printf("Hepatitis C.\n");
    printf("Dengue\n");
    printf("Tuberculosis.\n");
    printf("Polio.\n");
    PatientLogin();
}

void PatientSearch()
{
    char targetfirstname[100];
    char targetlastname[100];
    printf("Enter The First Name Of The Patient You Want To Search:");
    scanf("%s",targetfirstname);
    printf("Enter The Last Name Of The Patient You Want To Search:");
    scanf("%s",targetlastname);
    int flagfound=0;
    current=emergencyhead;
    while(current!=NULL)
    {
        if(strcmp(targetfirstname,current->firstpatientname)==0)
        {
            if(strcmp(targetlastname,current->lastpatientname)==0)
            {
                flagfound=1;
                break;
            }
        }
        current=current->next;
    }
    if(flagfound==0)
    {
        current=normalhead;
        while(current!=NULL)
        {
            if(strcmp(targetfirstname,current->firstpatientname)==0)
            {
                if(strcmp(targetlastname,current->lastpatientname)==0)
                {
                    flagfound=1;
                    break;
                }
            }
            current=current->next;
        }
    }
    if(current==NULL)
    {
        printf("Searched Patient Does Not Exist\n");
    }
    else
    {
        printf("Name: %s %s",current->firstpatientname,current->lastpatientname);
        printf("\n");
        printf("Address: %s",current->patientaddress);
        printf("\n");
        printf("Contact Number: %s",current->patientphone);
        printf("\n");
        printf("Email: %s",current->patientemail);
        printf("\n");
        printf("Marital Staus: %s",current->patientmarital);
        printf("\n");
        printf("Occupation: %s",current->patientoccupation);
        printf("\n");
        printf("Age: %d",current->patientage);
        printf("\n");
        if(current->patientsex==1)
        printf("Gender: Male");
        else if(current->patientsex==2)
        printf("Gender: Female");
        else
        printf("Gender: Others");
        printf("\n");
        printf("Family Members: %d",current->patientfamily);
        printf("\n");
        if(current->patientac==1)
        printf("AC Room: Yes");
        else
        printf("AC Room: No");
        printf("\n");
        printf("\n");
    }
    PatientLogin();
}

void Checkout()
{
    char targetfirstname[100];
    char targetlastname[100];
    printf("Enter The First Name Of The Patient:");
    scanf("%s",targetfirstname);
    printf("Enter The Last Name Of The Patient:");
    scanf("%s",targetlastname);
    int flagfound=0;
    current=emergencyhead;
    previous=NULL;
    while(current!=NULL)
    {
        if(strcmp(targetfirstname,current->firstpatientname)==0)
        {
            if(strcmp(targetlastname,current->lastpatientname)==0)
            {
                flagfound=1;
                break;
            }
        }
        previous=current;
        current=current->next;
    }
    if(flagfound==1)
    {
        printf("You Have To Pay 30,000 Rupees in Total\n");
        if(current==emergencyhead)
        {
            emergencyhead=current->next;
        }
        else
        {
            previous->next=current->next;
        }
    }
    else
    {
        current=normalhead;
        previous=NULL;
        while(current!=NULL)
        {
            if(strcmp(targetfirstname,current->firstpatientname)==0)
            {
                if(strcmp(targetlastname,current->lastpatientname)==0)
                {
                    flagfound=1;
                    break;
                }
            }
            current=current->next;
        }
        if(current==NULL)
        {
            printf("Patient Does Not Exist:\n");
        }
        else
        {
            printf("You Have To Pay 20,000 Rupees in Total\n");
            if(current==normalhead)
            {
                normalhead=current->next;
            }
            else
            {
                previous->next=current->next;
            }
        }
    }
    Start();
}

