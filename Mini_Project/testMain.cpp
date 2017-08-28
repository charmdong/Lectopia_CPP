
#include "HomeAutomation.h"
#include "Power.h"

int menu(char **menuList, int menuCnt); // 전달된 메뉴를 출력하고 정확한 메뉴번호를 리턴하는 함수
int controlMenuSelect(string message, int menuCnt); // 가전제품의 상태변경 처리를 위한 메뉴 함수
void displayTitle(string title); // 처리중인 내용 출력하기 위한 타이틀 출력함수 
void screen(HomeAutomation &rHa,Power &rPw); // 주메뉴를 출력하고 메뉴를 선택받아 반복적으로 주메뉴를 처리하는 함수
void listDisplayAppliance(HomeAutomation &rHa); // 등록된 가전제품의 상태출력
void controlAppliance(HomeAutomation &rHa); // 등록된 가전제품 제어하기
void addAppliance(HomeAutomation &rHa); // 가전제품 등록
void deleteAppliance(HomeAutomation &rHa); // 가전제품 삭제
void powerDisplay(Power &rPw, HomeAutomation &rHa);  // 전력소모량 출력
//int inputInteger(char *message);  //  message를 출력하고 정수값 입력 받아 리턴(문자, 실수값 예외 처리)
//int inputInteger(string message); //  message를 출력하고 정수값 입력 받아 리턴(문자, 실수값 예외 처리)
//void myFlush();  // cin입력 버퍼를 모두 비우고 fail상태를 초기상태로 재설정

int main()
{
	HomeAutomation homeAuto;
	Power power;
	screen(homeAuto, power);
	getchar(); getchar();
	return 0;
}

void screen(HomeAutomation &rHa,Power &rPw)
{
	char *menuList[]={"가전제품 상태확인 ", "가전제품 제어 ", "가전제품 등록 ", "가전제품 삭제 ", "종료 "};
	int menuCnt = sizeof(menuList)/sizeof(menuList[0]);
	int menuNum;

	displayTitle("홈 케어시스템 시작");
	while(true)
	{
		menuNum = menu(menuList, menuCnt);
		if(menuNum==menuCnt) {break;}
		switch(menuNum)
		{
		case 1 : listDisplayAppliance(rHa); break;
		case 2 : controlAppliance(rHa); break;
		case 3 : addAppliance(rHa); break;
		case 4 : deleteAppliance(rHa); break;
		}
	}
	powerDisplay(rPw, rHa);                    // 소모 전력량 출력
	displayTitle("홈 케어시스템 종료");
	return;
}
void listDisplayAppliance(HomeAutomation &rHa) // 등록된 가전제품의 상태출력
{
	displayTitle("가전제품 상태 보기");
	if(rHa.getApplianceCnt() == 0)
	{
		cout << "등록된 가전 제품이 없습니다" << endl;
	}
	else
	{
		rHa.listDisplayAppliance();
	}
	displayTitle("가전제품 상태 보기 종료");
}
void controlAppliance(HomeAutomation &rHa) // 등록된 가전제품 제어하기
{
	string machineName;  // 제품명
	bool res;

	displayTitle("가전제품 제어 하기");
	if(rHa.getApplianceCnt() == 0)
	{
		cout << "등록된 가전제품이 없습니다. 가전제품을 먼저 등록하세요." << endl;
		return;
	}
	
	cout << "* 제어할 제품명 입력 : ";
	cin >> machineName;
	res=rHa.controlAppliance(machineName);
	if(res) 
	{
		cout << "가전 제품명 : " << machineName << "의 제어가 완료되었습니다." << endl << endl;
	}
	else
	{
		cout << "가전 제품명 : " << machineName << "의 제어가 실패하였습니다." << endl << endl;
	}
}
void addAppliance(HomeAutomation &rHa) // 가전제품 등록
{
	string machineName;  // 제품명
	int powerConsumption; // 시간당 전력소모량
	Appliance *ap;  // 가전제품 클래스의 포인터 선언
	bool res;

	displayTitle("가전제품 등록 하기");
	string applianceList="1.밥솥 / 2.냉난방기 / 3.세탁기 : ";
	int applianceNum;

	applianceNum = controlMenuSelect(applianceList,3);
	cout << "* 제품명 입력( 예)큰밥솥, 세탁기 등) : ";
	cin >> machineName;
	powerConsumption= inputInteger("* 제품 전력소모량 입력(Kw/H) : ");
	
	switch(applianceNum)
	{
	case 1 : ap=new RiceCooker(machineName, powerConsumption); break;
	case 2 : ap=new AirConditioner(machineName, powerConsumption); break;
	case 3 : ap=new Washer(machineName, powerConsumption); break;
	}
	res=rHa.addAppliance(ap);
	if(res) 
	{
		cout << "가전 제품명 : " << machineName << "의 등록이 완료되었습니다." << endl << endl;
	}
	else
	{
		cout << "가전 제품명 : " << machineName << "의 등록이 실패하였습니다." << endl << endl;
	}
}
void deleteAppliance(HomeAutomation &rHa) // 가전제품 삭제
{
	string machineName;  // 제품명
	bool res;
	char choice;

	displayTitle("가전제품 삭제 하기");

	cout << "* 제품명 입력( 예)거실전등, 세탁기 등) : ";
	cin >> machineName;
	
	cout << "** 정말로 삭제하시겠습니까? (y/n) : ";
	cin >> choice;
	if (choice != 'Y' && choice != 'y')
		return;

	res=rHa.deleteAppliance(machineName);
	if(res) 
	{
		cout << "가전 제품명 : " << machineName << "의 삭제가 완료되었습니다." << endl << endl;
	}
	else
	{
		cout << "가전 제품명 : " << machineName << "의 삭제가 실패하였습니다." << endl << endl;
	}
}

void powerDisplay(Power &rPw, HomeAutomation &rHa)  // 전력소모량 출력
{
	int totalConsumption;

	totalConsumption = rPw.calPowerConsumption(rHa);
	cout <<"가전제품 총 전력소모량 : " << totalConsumption << endl << endl;
}

int controlMenuSelect(string message, int menuCnt)
{
	int menuNum;

	while(true)
	{
		menuNum = inputInteger(message);
		if(menuNum>0 && menuNum <= menuCnt){ break; }
	}
	return menuNum;
}

int menu(char **menuList, int menuCnt)
{
	int i;
	int menuNum=0; /* 입력된 메뉴 번호 저장 변수*/

	cout << endl << "==================================" << endl;
	for(i=0; i<menuCnt; i++)
	{
		cout << i+1 << "." << menuList[i] << endl;
	}
	cout << "==================================" << endl;
	while(menuNum<1 || menuNum>menuCnt)  /* 범위 내의 번호가 입력될 때 까지 반복*/
	{
		menuNum = inputInteger("# 메뉴번호를 입력하세요 : ");
		
	}
	return menuNum;
}   
void displayTitle(string title) // 화면 타이틀 출력 함수
{
	cout << endl << "------------------------------" << endl;
	cout << "    " << title << endl;
	cout << "------------------------------" <<endl;
}