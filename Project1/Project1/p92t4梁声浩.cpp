#include <iostream>
#include <string>
#include <cstring>

using namespace std;


struct Subject{
	
	char subject[20];
	int rate;
	Subject* next;
	Subject():next(NULL){}
	Subject(int rate,char arr[]):next(NULL){
		this->rate=rate;
		strncpy(this->subject,arr,sizeof(this->subject));
		
	}
};
struct Num2Sub{
	int rate;
	char subject[20]={};
};
struct Score{
	int num;
	int rate;
	int score;
	Score* next;
	Score():next(NULL){}
	Score(int StuNum,int num,int score):next(NULL){
		this->score=score;
		this->num=StuNum;
		this->rate=num;
	}
};
template <typename T>
struct Student{
	T num=0;
	char Name[20]={};
	int place;
	Student*next;
	Student():next(NULL){}
	Student(T d, const char*name,int place ):num(d),place(place),next(NULL){
		strncpy(this->Name,name,sizeof(name));
		
	}
	
};

void printScores(Student<int>* start, Subject* subjectstart, Score* scorestart) {
	Student<int>* currentStudent = start->next;
	while (currentStudent != NULL) {
		if(currentStudent->place==101){
			cout<<"=======101========"<<endl;
			cout << "学生：" << currentStudent->num<<"  " ;
			cout << currentStudent->Name << endl;
			Score* currentScore = scorestart->next;
			while(currentScore!=NULL){
				if(currentScore->num==currentStudent->num){
					Subject*currentSubject=subjectstart;
					while(currentSubject!=NULL){
						if(currentSubject->rate==currentScore->rate){
							cout<<currentSubject->subject<<"	"<<currentScore->score<<endl;
						}
						currentSubject=currentSubject->next;
					}
					
				}
				currentScore=currentScore->next;
			}
		}
		else
		{
			cout<<"=======102========"<<endl;
			cout << "学生学号：" << currentStudent->num << endl;
			cout << "学生：" << currentStudent->Name << endl;
			Score* currentScore = scorestart->next;
			while(currentScore!=NULL){
				if(currentScore->num==currentStudent->num){
					Subject*currentSubject=subjectstart;
					while(currentSubject!=NULL){
						if(currentSubject->rate==currentScore->rate){
							cout<<currentSubject->subject<<"	"<<currentScore->score<<endl;
						}
						currentSubject=currentSubject->next;
					}
					
				}
				currentScore=currentScore->next;
			}
		}
		
		currentStudent = currentStudent->next;
	}
}

int main(){
	int n,m,k;

	
	Student<int>* head = new Student<int>();
	Student<int>* start=head;
	Subject*subjecthead=new Subject();
	Subject*subjectstart= subjecthead;
	Score*scorehead=new Score();
	Score*scorestart=scorehead;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int num,place;
		char arr[20]={};
		cin>>num>>arr>>place;
		Student<int>*newStudent=new Student<int>(num,arr,place);
		head->next=newStudent;
		head=newStudent;
	}
	
	
	scanf("%d",&m);
	for(int i=0;i<m;++i){
		int rate={};
		char subject[20]={};
		cin>>rate>>subject;
		Subject*newSubject=new Subject(rate,subject);
		subjecthead->next=newSubject;
		subjecthead=subjecthead->next;
	}
	
	scanf("%d",&k);
	for(int i=0;i<k;++i){
		int StuNum,num,score;
		cin>>StuNum>>num>>score;
		Score*newScore=new Score(StuNum,num,score);
		scorehead->next=newScore;
		scorehead=scorehead->next;
	}
	printScores(start, subjectstart, scorestart);

	
}


