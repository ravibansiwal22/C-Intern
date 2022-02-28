#include <iostream>
#include <string.h>

using namespace std;
class Company
{
    public:
       int idCount=0,numEmp=0,empAge[100],empId[100];
       string empName[100];
       int eid;
       int dCount=0,numDep=0,DepId[100];
       string DepName[100];
       int id;
       
};
class DepartmentManagement: public Company
{
    public:
    bool checkName(string name)
    {
        bool flag = false;
        for(int i=0;i<dCount-1;i++)
        {
            int a = DepName[i].compare(name);
            if(a==0)
            {
                cout<<"\nDepartment"<<name<<" already exist\n";
                cout<<"\nRe-Enter name: ";
                flag = true;
            }
        }

        return flag;
    }

    void addDep()
    {
        int n;
        cout<<"\n\nEnter the number of depatments: ";
        cin>>n;
        numDep = numDep+n;

        cout<<"\nEnter department Detail's: ";
        for(int i = dCount; i<numDep; i++)
        {
            DepId[dCount] = ++dCount;
            cout<<"\ndepartment id: "<<dCount;
            cout<<"\nName: ";
            bool flag = true;
            while(flag)
            {
                cin>>DepName[i];
                flag = checkName(DepName[i]);
            }
             //  cout<<"Age: ";
             //  cin>>empAge[i];

        }

        printDepList();

    }

    void editDep()
    {
        int editId;
        cout<<"\n\nEnter the Id of the Department to edit: ";
        cin>>editId;

        bool flag = false;
        for(int i=0; i<numDep; i++)
        {
            if(editId==DepId[i])
            {
                flag = true;
                cout<<"\nDetails in Record:";
                cout<<"\nDepartment ID: "<<DepId[idCount];
                cout<<"\nName: "<<DepName[i];
               // cout<<"\nAge: "<<empAge[i];

                cout<<"\n\nEnter the Updated details:";
                cout<<"\nName: ";
                bool flagName = true;
                while(flagName)
                {
                    cin>>DepName[i];
                    flagName = checkName(DepName[i]);
                }
               // cout<<"Age: ";
                //cin>>empAge[i];

                cout<<"\nRecord Updated.";
                break;
            }
        }

        if(!flag)
            cout<<"Record Not Found!!!";
    }

    void printDepList()
    {
        cout<<"\n\n";
        cout<<"List of all departments";
        for(int i=0; i<numDep; i++)
        {
            cout<<"\nDepartment Id: "<<DepId[i]+1;
            cout<<"\nName: "<<DepName[i];
           // cout<<"\nAge: "<<empAge[i];
        }
    }
    void DeleteDepRecord()
    {
        cout<<"\nEnter the department Id you want to delete\n";
        cin>>id;
        for(int i=0;i<numDep;i++)
        {
            if(id==DepId[i])
            {
                DepName[i]=DepName[i+1];
                //empAge[i]=empAge[i+1];
                DepId[i]=DepId[i+1];
                numDep--;
            }
        }
        cout<<"Record deleted\n";
    }
};
    
class EmployeeManagement : public DepartmentManagement
{
    public:
    bool checkName(string name)
    {
        bool flag = false;
        for(int i=0;i<idCount-1;i++)
        {
            int a = empName[i].compare(name);
            if(a==0)
            {
                cout<<"\nEmployee "<<name<<" already exist\n";
                cout<<"\nRe-Enter name: ";
                flag = true;
            }
        }

        return flag;
    }

    void addEmp()
    {
        int n;
        cout<<"\n\nEnter the number of Employee: ";
        cin>>n;
        numEmp = numEmp+n;

        cout<<"\nEnter Employee Detail's: ";
        for(int i = idCount; i<numEmp; i++)
        {
            empId[idCount] = ++idCount;
            cout<<"\nEmployee id: "<<idCount;
            cout<<"\nName: ";
            bool flag = true;
            while(flag)
            {
                cin>>empName[i];
                flag = checkName(empName[i]);
            }
            cout<<"Age: ";
            cin>>empAge[i];

        }
        printList();
    }

    void editEmp()
    {
        int editId;
        cout<<"\n\nEnter the Id of the Employee to edit: ";
        cin>>editId;

        bool flag = false;
        for(int i=0; i<numEmp; i++)
        {
            if(editId==empId[i])
            {
                flag = true;
                cout<<"\nDetails in Record:";
                cout<<"\nEmployee ID: "<<empId[idCount];
                cout<<"\nName: "<<empName[i];
                cout<<"\nAge: "<<empAge[i];

                cout<<"\n\nEnter the Updated details:";
                cout<<"\nName: ";
                bool flagName = true;
                while(flagName)
                {
                    cin>>empName[i];
                    flagName = checkName(empName[i]);
                }
                cout<<"Age: ";
                cin>>empAge[i];

                cout<<"\nRecord Updated.";
                break;
            }
        }

        if(!flag)
        cout<<"Record Not Found!!!";
    }


    void DeleteRecord()
    {
        cout<<"\nEnter the Employee Id you want to delete: \n ";
        cin>>eid;
        for(int i=0;i<numEmp;i++)
        {
            if(eid==empId[i])
            {
                empName[i]=empName[i+1];
                empAge[i]=empAge[i+1];
                empId[i]=empId[i+1];
                numEmp--;
            }
            
        }
        cout<<"Record deleted\n";
        printList();
    }
    void printList()
    {
        cout<<"\n\n";
        cout<<"List of all Employees";
        for(int i=0; i<numEmp; i++)
        {
            cout<<"\nEmployee Id: "<<empId[i]+1;
            cout<<"\nName: "<<empName[i];
            cout<<"\nAge: "<<empAge[i];
        }
    }
};
int main()
{   
    char ch1;
    int ch;
    do
    {
        EmployeeManagement obj;
        cout<<"1.Add employees\n2.Edit Employee\n3.Delete Employee\n4.Print List of employees\n5.Add Department\n6.Edit Department\n7.Delete Depatment\n8.Print List of Depatments\n";
        cout<<"\nenter your choice\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            obj.addEmp();
            break;
            case 2:
            obj.editEmp();
            break;
            case 3:
            obj.DeleteRecord();
            break;
            case 4:
            obj.printList();
            break;
            case 5:
            obj.addDep();
            break;
            case 6:
            obj.editDep();
            break;
            case 7:
            obj.DeleteDepRecord();
            break;
            case 8:
            obj.printDepList();
            break;
            default:
            cout<<"invaild choice";
        }
        cout<<"\nDo you want to continue y/n: ";
        cin>>ch1;
    }
    while(ch1!='n');
    return 0;
}