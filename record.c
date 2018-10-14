#include<stdio.h>
#include<malloc.h>
#include<string.h>

int count = 0; 

struct student
{
	struct student *next;	
	int rollno,marks;
	char name[100];
}	*start=NULL,*end=NULL;


void display_all()
{
 int i;
 struct student *t1 = start;
 
 if(start==NULL)
 	{
 		printf("\tNo Record Found.");
 	}
 
 else
 	{
 	while(t1->next!=NULL)
 		{
 			printf("\n\n\t Roll No.: %d", t1->rollno);
 			printf("\n\t Name: %s", t1->name);
 			printf("\n\t Marks: %d\n", t1->marks);
 			printf("%u",t);
 			t1=t1->next;
 		}
 	printf("\n\t Roll No.: %d", t1->rollno);
 	printf("\n\t Name: %s", t1->name);
 	printf("\n\t Marks: %d", t1->marks); 
	} 
	
  printf("\n\tNumber of total records: %d", count);
}


void display_part()
{
 int i,val;
 struct student *t1 = start;
 printf("\n\t\t Enter the Roll No. of the Student for Details: ");
 scanf("\t %d",&val);
 while(t1->rollno!=val)
 	{
  		t1=t1->next;
 	}
 	printf("\n\t Roll No.: %d", t1->rollno);
 	printf("\n\t Name: %s", t1->name);
 	printf("\n\t Marks: %d", t1->marks);
}



void delete_record()
{
struct student *ptr = start,*temp = start,*t_end = start;
int val;
printf("\n\t Enter the Roll No. of the Record to be Deleted: ");
scanf("\t %d",&val);

	if(start==NULL)
	{
		printf("\nList is Empty.\n");
	}

	else if(start->next==NULL)
	{
		start = NULL;
		end = NULL;
		count = 0;
	}

	else if(ptr->rollno==val)
	{

		start = start->next;
		count = 0;
	}

	else if(end->rollno == val)
	{
		while(t_end->next!= end)
		{
			t_end = t_end->next;
		}
		t_end->next=NULL;
		end = t_end;
		count--;
	}

	else
	{
		while(ptr->rollno!= val)
		{
			temp = ptr;
			ptr = ptr -> next;
		}
		temp -> next = ptr -> next;
		free(ptr);
		count--;
	}
}


void insert_record()
{
	struct student *ptr;
	ptr = (struct student*) malloc (sizeof(struct student));
	int r,m; char n[20];
	
	printf("\n\t\t\t Please Enter Student Roll No.: ");
	scanf("\t %d",&r);
	
	printf("\n\t\t\t Please Enter Student Name: ");
	scanf("\t %s",n);
	
	printf("\n\t\t\t Please Enter Student Marks: ");
	scanf("\t %d",&m);
	
	ptr->rollno = r;
	strcpy(ptr->name,n);
	ptr->marks = m;
	ptr->next = NULL;
		
	if(start==NULL)
	{
	    start=ptr;
	    end=ptr;
	    count = 1;
	}
	
	else 
	{
	    end->next=ptr;	
	    end=ptr;
	    count++;
    }
    
    printf("\n\t  Record Registered.\n");
}

void topper() 
{ 
   struct student *t = start, *max = start;
   int i;
   for(i=0; i<count; i++)
   {
   		while( t->next != NULL)
		{
   			t = t->next;
   			if( (t->marks) > (max->marks) )
   			{
   				max = t;
			}
		
			else
				continue;
   		}
	}
	
	printf("\n\t Deatails of Topper: ");
	printf("\n\t Roll No.: %d", max->rollno);
 	printf("\n\t Name: %s", max->name);
 	printf("\n\t Marks: %d", max->marks); 	
	
}


void main()
{

int choice;
printf(" \n\t\t\t\t\t STUDENT PERFORMANCE RECORD\n");
printf("\t\t____________________________________________________________________________________");

while(1)
{
	printf("\n\n\t\t 1.Display Details of All Students.     2.Display Deatail of a Particular Student.\n\t\t 3.Delete a Record.   \t\t\t4.Edit a Record.\n\t\t 5.New Record.   \t\t\t6.Display Topper.\n\t\t 7.Exit. ");
	
	printf("\n\n\t Enter your option:  ");
	scanf("%d", &choice);	
	
	switch(choice)
	{
	case 1:display_all(); break;
	case 2:display_part(); break;
	case 3:delete_record(); break;
	case 4:delete_record();
	case 5:insert_record(); break;
	case 6:topper(); break;
	case 7:exit(0); break;
	default: printf("\n\n\tInvalid Choice.");
	}
} 
}



/*
OUTPUT:


                                         STUDENT PERFORMANCE RECORD
                ____________________________________________________________________________________

                 1.Display Details of All Students.     2.Display Deatail of a Particular Student.
                 3.Delete a Record.                     4.Edit a Record.
                 5.New Record.                          6.Display Topper.
                 7.Exit.

         Enter your option:  5

                         Please Enter Student Roll No.: 3

                         Please Enter Student Name: Ron

                         Please Enter Student Marks: 98

          Record Registered.


                 1.Display Details of All Students.     2.Display Deatail of a Particular Student.
                 3.Delete a Record.                     4.Edit a Record.
                 5.New Record.                          6.Display Topper.
                 7.Exit.

         Enter your option:  5

                         Please Enter Student Roll No.: 9

                         Please Enter Student Name: Harry

                         Please Enter Student Marks: 87

          Record Registered.


                 1.Display Details of All Students.     2.Display Deatail of a Particular Student.
                 3.Delete a Record.                     4.Edit a Record.
                 5.New Record.                          6.Display Topper.
                 7.Exit.

         Enter your option:  1


         Roll No.: 3
         Name: Ron
         Marks: 98

         Roll No.: 9
         Name: Harry
         Marks: 87
        Number of total records: 2

                 1.Display Details of All Students.     2.Display Deatail of a Particular Student.
                 3.Delete a Record.                     4.Edit a Record.
                 5.New Record.                          6.Display Topper.
                 7.Exit.

         Enter your option:  2

                 Enter the Roll No. of the Student for Details: 9

         Roll No.: 9
         Name: Harry
         Marks: 87

                 1.Display Details of All Students.     2.Display Deatail of a Particular Student.
                 3.Delete a Record.                     4.Edit a Record.
                 5.New Record.                          6.Display Topper.
                 7.Exit.

         Enter your option:  5

                         Please Enter Student Roll No.: 15

                         Please Enter Student Name: Max

                         Please Enter Student Marks: 56

          Record Registered.


                 1.Display Details of All Students.     2.Display Deatail of a Particular Student.
                 3.Delete a Record.                     4.Edit a Record.
                 5.New Record.                          6.Display Topper.
                 7.Exit.

         Enter your option:  1


         Roll No.: 3
         Name: Ron
         Marks: 98


         Roll No.: 9
         Name: Harry
         Marks: 87

         Roll No.: 15
         Name: Max
         Marks: 56
        Number of total records: 3

                 1.Display Details of All Students.     2.Display Deatail of a Particular Student.
                 3.Delete a Record.                     4.Edit a Record.
                 5.New Record.                          6.Display Topper.
                 7.Exit.

         Enter your option:  3

         Enter the Roll No. of the Record to be Deleted: 9


                 1.Display Details of All Students.     2.Display Deatail of a Particular Student.
                 3.Delete a Record.                     4.Edit a Record.
                 5.New Record.                          6.Display Topper.
                 7.Exit.

         Enter your option:  1


         Roll No.: 3
         Name: Ron
         Marks: 98

         Roll No.: 15
         Name: Max
         Marks: 56
        Number of total records: 2

                 1.Display Details of All Students.     2.Display Deatail of a Particular Student.
                 3.Delete a Record.                     4.Edit a Record.
                 5.New Record.                          6.Display Topper.
                 7.Exit.

         Enter your option:  4

         Enter the Roll No. of the Record to be Deleted: 3

                         Please Enter Student Roll No.: 3

                         Please Enter Student Name: Ron

                         Please Enter Student Marks: 78

          Record Registered.


                 1.Display Details of All Students.     2.Display Deatail of a Particular Student.
                 3.Delete a Record.                     4.Edit a Record.
                 5.New Record.                          6.Display Topper.
                 7.Exit.

         Enter your option:  1


         Roll No.: 15
         Name: Max
         Marks: 56

         Roll No.: 3
         Name: Ron
         Marks: 78
        Number of total records: 1

                 1.Display Details of All Students.     2.Display Deatail of a Particular Student.
                 3.Delete a Record.                     4.Edit a Record.
                 5.New Record.                          6.Display Topper.
                 7.Exit.

         Enter your option:  6

         Deatails of Topper:
         Roll No.: 3
         Name: Ron
         Marks: 78

                 1.Display Details of All Students.     2.Display Deatail of a Particular Student.
                 3.Delete a Record.                     4.Edit a Record.
                 5.New Record.                          6.Display Topper.
                 7.Exit.

         Enter your option:  7
         
*/
