#include<iostream>
#include<conio.h>
using namespace std;
class Teacher{
	public:
	string name;
	int arriveTime;
	int leaveTime;
	int prep;
	int effectiveCom;
	int additionalMaterial;
	int encouragement;
	int officeAvail;
	int giveRespect;
	int tempAndComf;
	int courseCompletion;
	int materialUpdate;
	int knowlegdeIncrease;
	int examCoverability;
	int fairExamining;
	int showResultInTime;
	int wellManagedLabs;
	int labsRegularity;
	int labEngrGuidance;
	int instrLabInvolve;
	int modernEquipement;
};
int numbering(int num);
void bestFeature(int max);
int main(){
	int numberOfTeacher,temp;
	
	cout<<"Marks always entered in range 1-5 if entered greater than 5 it will be considered as 5\n";
	cout<<"Enter number of teachers : ";
	cin>>numberOfTeacher;
	Teacher array[numberOfTeacher];
	int totalMarks[numberOfTeacher];
	for(int i=0;i<numberOfTeacher;i++){
		cout<<"\n\nEnter name of Teacher : ";
		cin>>array[i].name;
		cout<<"Instructor Arrives on time : ";
		cin>>temp;
		array[i].arriveTime=numbering(temp);
		
		cout<<"Instructor Leaves on time : ";
		cin>>temp;
		array[i].leaveTime=numbering(temp);
		
		cout<<"Instructor Prepared For Class : ";
		cin>>temp;
		array[i].prep=numbering(temp);
		
		cout<<"Instructor Effective Communication : ";
		cin>>temp;
		array[i].effectiveCom=numbering(temp);
		
		cout<<"Instructor Provide Additional Material than text books : ";
		cin>>temp;
		array[i].additionalMaterial=numbering(temp);
		
		cout<<"Instructor Encourage Students to ask questions : ";
		cin>>temp;
		array[i].encouragement=numbering(temp);
		
		cout<<"Instructor Remain Available for consultation during office hours : ";
		cin>>temp;
		array[i].officeAvail=numbering(temp);
		
		
		cout<<"Instructor Show Respect towards students : ";
		cin>>temp;
		array[i].giveRespect=numbering(temp);
		
		cout<<"Instructor Maintain Temprament and Comfortable environment in class : ";
		cin>>temp;
		array[i].tempAndComf=numbering(temp);
		
		cout<<"Instructor Completes the whole course : ";
		cin>>temp;
		array[i].courseCompletion=numbering(temp);
		
		cout<<"Course material is modern and updated : ";
		cin>>temp;
		array[i].materialUpdate=numbering(temp);
		
		cout<<"Subject matter increase your knowledge : ";
		cin>>temp;
		array[i].knowlegdeIncrease=numbering(temp);
		
		cout<<"Assignment, Quizes and Exams covers the material presented in the course : ";
		cin>>temp;
		array[i].examCoverability=numbering(temp);
		
		cout<<"Instructor is Fair in examination : ";
		cin>>temp;
		array[i].fairExamining=numbering(temp);
		
		cout<<"Instructor Return the grade scripts etc in reasonable amount of time : ";
		cin>>temp;
		array[i].showResultInTime=numbering(temp);
		
		cout<<"Lab sessions are well managed and synchronized with thery lecture : ";
		cin>>temp;
		array[i].wellManagedLabs=numbering(temp);
		
		cout<<"Labs were conducted regularly : ";
		cin>>temp;
		array[i].labsRegularity=numbering(temp);
		
		cout<<"Lab engineer demonstrates well during lab sessionals: ";
		cin>>temp;
		array[i].labEngrGuidance=numbering(temp);
		
		cout<<"Course instructor is fully involved in lab conduction and evaluation : ";
		cin>>temp;
		array[i].instrLabInvolve=numbering(temp);
		
		cout<<"Equipments used for conduction of labs were modern and updated : ";
		cin>>temp;
		array[i].modernEquipement=numbering(temp);
	}
	
	for(int i=0;i<numberOfTeacher;i++){
		
		cout<<"\n\nName of Teacher : "<<array[i].name;
		
		cout<<"\nInstructor Arrives on time : "<<array[i].arriveTime;
		
		cout<<"\nInstructor Leaves on time : "<<array[i].leaveTime;
		
		cout<<"\nInstructor Prepared For Class : "<<array[i].prep;
		
		cout<<"\nInstructor Effective Communication : "<<array[i].effectiveCom;
		
		cout<<"\nInstructor Provide Additional Material than text books : "<<array[i].additionalMaterial;
		
		cout<<"\nInstructor Encourage Students to ask questions : "<<array[i].encouragement;
		
		cout<<"\nInstructor Remain Available for consultation during office hours : "<<array[i].officeAvail;
		
		
		cout<<"\nInstructor Show Respect towards students : "<<array[i].giveRespect;
		
		cout<<"\nInstructor Maintain Temprament and Comfortable environment in class : "<<array[i].tempAndComf;
		
		cout<<"\nInstructor Completes the whole course : "<<array[i].courseCompletion;
		
		cout<<"\nCourse material is modern and updated : "<<array[i].materialUpdate;
		
		cout<<"\nSubject matter increase your knowledge : "<<array[i].knowlegdeIncrease;
		
		cout<<"\nAssignment, Quizes and Exams covers the material presented in the course : "<<array[i].examCoverability;
		
		cout<<"\nInstructor is Fair in examination : "<<array[i].fairExamining;
		
		cout<<"\nInstructor Return the grade scripts etc in reasonable amount of time : "<<array[i].showResultInTime;
		
		cout<<"\nLab sessions are well managed and synchronized with thery lecture : "<<array[i].wellManagedLabs;
		
		cout<<"\nLabs were conducted regularly : "<<array[i].labsRegularity;
		
		cout<<"\nLab engineer demonstrates well during lab sessionals: "<<array[i].labEngrGuidance;
		
		cout<<"\nCourse instructor is fully involved in lab conduction and evaluation : "<<array[i].instrLabInvolve;
		
		cout<<"\nEquipments used for conduction of labs were modern and updated : "<<array[i].modernEquipement<<endl;
	}
	
	for(int i=0;i<numberOfTeacher;i++){
		totalMarks[i]=array[i].arriveTime+array[i].leaveTime+array[i].prep+array[i].effectiveCom+array[i].additionalMaterial+array[i].encouragement+array[i].officeAvail+array[i].giveRespect+array[i].tempAndComf+array[i].courseCompletion+array[i].materialUpdate+array[i].knowlegdeIncrease+array[i].examCoverability+array[i].fairExamining+array[i].showResultInTime+array[i].wellManagedLabs+array[i].labsRegularity+array[i].labEngrGuidance+array[i].instrLabInvolve+array[i].modernEquipement;
	}
	int maxMarks=0,maxTeach;
	int minMarks=100,minTeach;
	for(int i=0;i<numberOfTeacher;i++){
		if(totalMarks[i]>maxMarks){
			maxMarks=totalMarks[i];
			maxTeach=i;
		}
		if(totalMarks[i]<minMarks){
			minMarks=totalMarks[i];
			minTeach=i;
		}
//		cout<<"\n"<<array[i].name<<" Marks : "<<totalMarks[i];
	}
	cout<<"\nBest teacher is "<<array[maxTeach].name<<" with "<<totalMarks[maxTeach];
	cout<<"\nWorst teacher is "<<array[minTeach].name<<" with "<<totalMarks[minTeach];
	
	int features[20];
	for(int j=0;j<20;j++){
			features[j]=0;
		}
		for(int i=0;i<numberOfTeacher;i++){
			features[0]+=array[i].arriveTime;
			features[1]+=array[i].leaveTime;
			features[2]+=array[i].prep;
			features[3]+=array[i].effectiveCom;
			features[4]+=array[i].additionalMaterial;
			features[5]+=array[i].encouragement;
			features[6]+=array[i].officeAvail;
			features[7]+=array[i].giveRespect;
			features[8]+=array[i].tempAndComf;
			features[9]+=array[i].courseCompletion;
			features[10]+=array[i].materialUpdate;
			features[11]+=array[i].knowlegdeIncrease;
			features[12]+=array[i].examCoverability;
			features[13]+=array[i].fairExamining;
			features[14]+=array[i].showResultInTime;
			features[15]+=array[i].wellManagedLabs;
			features[16]+=array[i].labsRegularity;
			features[17]+=array[i].labEngrGuidance;
			features[18]+=array[i].instrLabInvolve;
			features[19]+=array[i].modernEquipement;
		}
		
		
		int maxFeature=0;
		for(int j=0;j<20;j++){
			features[j];
			if(features[maxFeature]<features[j])
				maxFeature=j;
			cout<<"\n"<<features[j];
		}
		bestFeature(maxFeature);
	getch();
	return 0;
}
void bestFeature(int max){
	switch(max){
		case 0:
			cout<<"\nInstructor Arrives on time.";
			break;
		case 1:
			cout<<"\nInstructor Leaves on time.";
			break;
		case 2:
		cout<<"\nInstructor Prepared For Class.";
			break;
		case 3:
		cout<<"\nInstructor Effective Communication.";
			break;
		case 4:
		cout<<"\nInstructor Provide Additional Material than text books.";
			break;
		case 5:
		cout<<"\nInstructor Encourage Students to ask questions.";
			break;
		case 6:
		cout<<"\nInstructor Remain Available for consultation during office hours.";
			break;
		case 7:
		cout<<"\nInstructor Show Respect towards students.";
			break;
		case 8:
		cout<<"\nInstructor Maintain Temprament and Comfortable environment in class.";
			break;
		case 9:
		cout<<"\nInstructor Completes the whole course.";
			break;
		case 10:
		cout<<"\nCourse material is modern and updated.";
			break;
		case 11:
		cout<<"\nSubject matter increase your knowledge.";
			break;
		case 12:
		cout<<"\nAssignment, Quizes and Exams covers the material presented in the course.";
			break;
		case 13:
		cout<<"\nInstructor is Fair in examination.";
			break;
		case 14:
		cout<<"\nInstructor Return the grade scripts etc in reasonable amount of time.";
			break;
		case 15:
		cout<<"\nLab sessions are well managed and synchronized with thery lecture.";
			break;
		case 16:
		cout<<"\nLabs were conducted regularly.";
			break;
		case 17:
		cout<<"\nLab engineer demonstrates well during lab sessionals.";
			break;
		case 18:
		cout<<"\nCourse instructor is fully involved in lab conduction and evaluation.";
			break;
		case 19:
		cout<<"\nEquipments used for conduction of labs were modern and updated.";		
	}
}
int numbering(int num){
	int tmp=num;
	if(num>5)
		tmp=5;
	else if(num<1){
		tmp=1;
	}
	return tmp;
}
