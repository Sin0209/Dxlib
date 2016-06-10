#include "DxLib.h"
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine, int nCmdShow )
{
	SetGraphMode( 1920 , 1080 , 32 );
	ChangeWindowMode(TRUE);

	if( DxLib_Init() == -1 )return -1;
	SetDrawScreen(DX_SCREEN_BACK); 
	int iroiro[12],zikix=965,zikiy=740,i=0,zikianimation=0,cr;
	//int tamax,tamay,tamasonzai,tamagazou[2],tamaanimation=0,tamaanimationX=0;
	//すたああああああああああああああああと
	int muda = 0;
	int scene = 1;
	int start,waku;
	int end,end2,en,enen;
	en=1;
	cr = GetColor( 255 ,  240 , 0 );
	waku = GetColor(255, 255, 255);
	end = LoadGraph("Resource\\YES.png");	//YES
	end2 = LoadGraph("Resource\\NO.png");//NO
	//ロード
	for(i = 0;i < 12;i++){
		LoadDivGraph("Resource\\iroiro.png",12,4,5,50,50,iroiro);
	}
	//LoadDivGraph("Resource\\tama,png",2,1,16,12,16,tamagazou);
	//スタート
	start = LoadGraph("Resource\\start2.png");






	while(1){                              //ちょうつよい
		switch(scene){
		case 1:
			while(1){
				ClearDrawScreen();
				DrawRotaGraph(zikix,zikiy,2.0,0,start,TRUE,FALSE);
				if(CheckHitKey(KEY_INPUT_ESCAPE)){
					scene = 2;
					break;
				}
				ScreenFlip();
			}
		case 2:
			while(1){
				ClearDrawScreen() ;
				//自機キャラアニメーション
				if(
					(CheckHitKey(KEY_INPUT_W) == 0 && CheckHitKey(KEY_INPUT_S) == 0 && CheckHitKey(KEY_INPUT_A) == 0 && CheckHitKey(KEY_INPUT_D) == 0) ||
					(CheckHitKey(KEY_INPUT_W)==1&&CheckHitKey(KEY_INPUT_S)==0&&CheckHitKey(KEY_INPUT_A)==0&&CheckHitKey(KEY_INPUT_D)==0) ||
					(CheckHitKey(KEY_INPUT_W)==0&&CheckHitKey(KEY_INPUT_S)==1&&CheckHitKey(KEY_INPUT_A)==0&&CheckHitKey(KEY_INPUT_D)==0) ||
					(CheckHitKey(KEY_INPUT_W)==1&&CheckHitKey(KEY_INPUT_S)==1&&CheckHitKey(KEY_INPUT_A)==0&&CheckHitKey(KEY_INPUT_D)==0)){           
						zikianimation++;
						if(zikianimation==40)zikianimation=0;
						if (zikianimation % 40 < 10)
							DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[0],TRUE,FALSE);
						else if (zikianimation % 40 < 20)
							DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[1],TRUE,FALSE);
						else if (zikianimation % 40 < 30)
							DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[2],TRUE,FALSE);
						else if (zikianimation % 40 < 40)
							DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[3],TRUE,FALSE);
				}
				if( CheckHitKey(KEY_INPUT_W)==1){
					zikiy-=5;
					if(CheckHitKey(KEY_INPUT_LSHIFT )==1)zikiy-=8;	
					if(zikiy<0)zikiy=0;
				}
				if( CheckHitKey(KEY_INPUT_S)==1){
					zikiy+=5;
					if(CheckHitKey(KEY_INPUT_LSHIFT )==1)zikiy+=8;
					if(zikiy>1080)zikiy=1080;
				}
				if(CheckHitKey(KEY_INPUT_D)==1){
					zikix+=5;/*アニメーション右*/
					if(CheckHitKey(KEY_INPUT_LSHIFT )==1)zikix+=8;
					if(zikix>1920)zikix=1920;
					zikianimation++;if(zikianimation==40)zikianimation=0;
					if(zikianimation<10)DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[4],TRUE,FALSE);
					else if(zikianimation<20)DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[5],TRUE,FALSE);
					else if(zikianimation<30)DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[6],TRUE,FALSE);
					else if(zikianimation<40)DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[7],TRUE,FALSE);
					if(CheckHitKey(KEY_INPUT_A)==1){/*アニメーション左*/
						if(zikianimation==40)zikianimation=0;zikianimation--;
						if (zikianimation % 40 < 10)
							DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[0],TRUE,FALSE);
						else if (zikianimation % 40 < 20)
							DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[1],TRUE,FALSE);
						else if (zikianimation % 40 < 30)
							DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[2],TRUE,FALSE);
						else if (zikianimation % 40 < 40)
							DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[3],TRUE,FALSE);
					}
				}
				if(CheckHitKey(KEY_INPUT_A)==1){
					zikix-=5;
					if(CheckHitKey(KEY_INPUT_LSHIFT )==1)zikix-=8;
					/*アニメーション左*/
					if(zikix<0)zikix=0;
					zikianimation++;if(zikianimation==40)zikianimation=0;
					if(zikianimation<10)DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[8],TRUE,FALSE);
					else if(zikianimation<20)DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[9],TRUE,FALSE);
					else if(zikianimation<30)DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[10],TRUE,FALSE);
					else if(zikianimation<40)DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[11],TRUE,FALSE);
					if(CheckHitKey(KEY_INPUT_D)==1){
						if(zikianimation==40)zikianimation=0;
						if (zikianimation % 40 < 10)
							DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[0],TRUE,FALSE);
						else if (zikianimation % 40 < 20)
							DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[1],TRUE,FALSE);
						else if (zikianimation % 40 < 30)
							DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[2],TRUE,FALSE);
						else if (zikianimation % 40 < 40)
							DrawRotaGraph(zikix,zikiy,2.0,0,iroiro[3],TRUE,FALSE);
					}
				}
				DrawBox( zikix-3, zikiy-3 , zikix+7 , zikiy+7 , cr , TRUE) ; 
				//自機キャラアニメーション終了
				if(CheckHitKey(KEY_INPUT_ESCAPE)==1){
					muda++;
					if(muda>10){
						scene=3;
						break;
					}
				}
				else muda=0;
				ScreenFlip();
			}
		case 3:
			while(1){
				if(CheckHitKey(KEY_INPUT_LEFT)==1)en=1;
				if(CheckHitKey(KEY_INPUT_RIGHT)==1)en=0;
				if(en==1){
					DrawRotaGraph( 965 , 740 , 1 , 0 , end , TRUE ) ;
					if(CheckHitKey(KEY_INPUT_RETURN)==1){
						enen=1;
						break;		
					}
				}
				if(en==0){
					DrawRotaGraph( 965 , 740 , 1 , 0 , end2 , TRUE ) ;
					if(CheckHitKey(KEY_INPUT_RETURN)==1){
						scene=2;
						break;	
					}
				}
				ScreenFlip();
			}
		}
		if(enen==1)break;
		ScreenFlip();
	}
	DxLib_End();
	return 0 ;				// ソフトの終了
}
