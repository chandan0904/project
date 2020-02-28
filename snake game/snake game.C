#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<conio.h>
#include<alloc.h>
#include<stdio.h>
int i =20 , j = 150 , tmp = 0, a = 300 , b = 300,T=12;
int x = 1 , y = 0 , res = 100 , e=0,E=0,ext=0;
long k=0,scr=0,cun=70;

typedef struct dnode
{
	int x,y;
	struct dnode *next;

} node;

node  *h = NULL;

int  menu();
void menu_l(int );
void help(int);
int  m_test(int , int);
int  drow();
void scr_menu(int);
void cir_d();
int  drow_s();
void test();
int  key_b( int );
void new_g();
void lvl_menu();
int l_test(int,int);
void level();



void new_g()
{
	 i =20 , j = 150 , cun = 70 , scr = 0 , k = 0 , tmp = 0, a = 300 , b = 300;
	 x = 1 , y = 0 , res = 100 , e=0,E=0;
	 h=NULL;
}


//
int drow()
{
	int ch;
	node *temp,*ptr;

	E=0;
	setcolor(14);
	line(i,j,i,j);
	ptr=(node *)malloc(sizeof(node));
	ptr-> x = i;
	ptr-> y =  j;
	ptr-> next = NULL;
	if(h == NULL)
	{
		h = ptr;
	}
	else
	{
		temp = h;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = ptr;

	}

	setcolor(4);
	temp = h;
	while(temp->next != NULL)
	{

		if( temp-> x == ptr->x && temp->y == ptr->y)
		{
			setcolor(4);
			outtextxy(250,190,"GAME OVER");
			scr_menu(0);
			setcolor(15);
			outtextxy(480,380,"Press x to Exit");
			//getch();
			while(1)
			{
				if(kbhit())
				{       ch=getch();
					if(ch==120)
					{
						E=1;
						ext=1;
						break; //	exit(1);
					}
				}
				delay(10);

			}
		}
		temp = temp-> next;
	}

	cir_d();
	scr = scr + tmp;
	if( k >= (70 + scr) )
	{
		temp=h;
		setcolor(0);
		line(temp->x,temp->y,temp->x,temp->y);
		h=temp->next;
		free(temp);

	}
	return 	E;

}
//
void scr_menu(int c)
{
		setcolor(c);
		outtextxy(400,420,"Press x to Exit");
		outtextxy(120,420,"Press P to Pause");
		outtextxy(120,420,"Press C to Continue");

}


//
void cir_d()
{
	circle(a,b,1);
	circle(a,b,2);
	circle(a,b,3);
	if( ( (i+3) == a || (a+3) == i) && ( ( (b+3) - j) <= 6 && ((b+3)-j) >= 1 ) )
	{
		setcolor(0);
		circle(a,b,1);
		circle(a,b,2);
		circle(a,b,3);
		tmp=2;

	}
	else if( ( j+3 ==b || b+3 == j ) && (a+3) - i <= 6 && (a+3) - i >= 1 )
	{
		setcolor(0);
		circle(a,b,1);
		circle(a,b,2);
		circle(a,b,3);
		tmp=2;

	}
	else
	{
		tmp=0;

	}

}
//
int drow_s()
{
	int ch;


	if(drow())
	{
		E=1;
		return E;

	}
	if(kbhit())
	{       ch=getch();

		if(!key_b( ch ))
		{
			E=1;
			return E;

		}
	}

	if(tmp==2)
	{
		a += 109;
		b += 70;
		if( a>=getmaxx()-25 || a<=25)
		{
			a=29;
		}
		if( b>=395 || b<=25)
		{
			b=39;
		}
		k=cun++;
	}
	i=i+x;
	j=j+y;

	test();

	return 0;
}
//

void test()
{
	if(i >= getmaxx()-20 )
	{
		i=20;
	}
	else if(i < 20 )
	{
		i=getmaxx()-20;
	}
	if(j >= 400)
	{
		j=20;
	}
	else if(j < 20)
	{
		j=400;
	}



}

//
int key_b( int ch)
{
	E=1;

	if(ch==72 && res!=80)
	{
		x=0;
		y=-1;
		res=72;
	}
	if(ch==75 && res!= 77)
	{
		x=-1;
		y=0;
		res=75;

	}
	if(ch== 77 && res!=75)
	{
		x=1;
		y=0;
		res=77;

	}
	if(ch==80 && res != 72)
	{
		x=0;
		y=1;
		res=80;
	}
	if(ch==120 )
	{
	      E=0;
	    //return E;   //	exit(0);
	}
	if(ch==112)
	{
		int c;
		setcolor(0);
		outtextxy(120,420,"Press P to Pause");
		setcolor(15);
		outtextxy(120,420,"Press C to Continue");
		while(1)
		{
			if(kbhit())
			{	c=getch();
				if(c==99)
				{
					setcolor(0);
					outtextxy(120,420,"Press C to Continue");
					break;
				}
				if(c==120)
				{

				      E=0;
				      //return 0;
				      // exit(0);
				   //	menu();
				  //break;
				  return 0;
				}
			}
			delay(10);
		}
	}



       return E;
}
//

void lvl_menu(int c)
{


	setcolor(c);
	settextstyle(1,0,0);
	outtextxy(270,30,"LEVEL");
	settextstyle(0,0,0);
	//setcolor(c);
	outtextxy(280,150,"SIMPLE");
	outtextxy(280,180,"MIDIUM");
	outtextxy(286,210,"HIGH");
	outtextxy(30,370,"Press Esc to Main Menu ");
	outtextxy(330,370,"Press D or U to Select ");




}


int l_test(int ch,int l)
{
	if(ch==100)
	{
		l++;
		if(l>=4)
		{
		    l=1;

		}

	}
	else if(ch==117)
	{
		l--;
		if(l<=0)
		{
			l=3;
		}

	}


	return l;
}





void level()
{
	int ch=0,l=0;

	lvl_menu(15);
	while(l==0&&ch!=27)
	{
		if(kbhit)
		{
			ch=getch();
			l=l_test(ch,l);
			if(l!=0)



			{

				setcolor(0);
				outtextxy(330,370,"Press D or U to Select ");
				setcolor(15);
				outtextxy(420,370,"Press Enter to Active");

			}
		}
		delay(20);
	}






	while(ch!=27)
	{

		if(l==1)
		{
			setcolor(4);
			outtextxy(280,150,"SIMPLE");

			while(1)
			{
				if(kbhit)
				{
					ch=getch();
					l=l_test(ch,l);
				}
				if(l==2||l==3)
				{
					setcolor(15);
					outtextxy(280,150,"SIMPLE");
					//l=27;
					break;

				}
				else if(ch==13)
				{
					T=15;
					ch=27;
					break;

				}
				else if(ch==27);
				{
					break;
				}

				delay(10);

			}

		}
		if(l==2)
		{
			setcolor(4);
			outtextxy(280,180,"MIDIUM");
			while(1)
			{
				if(kbhit)
				{
					ch=getch();
					l=l_test(ch,l);
				}
				if(l==3||l==1)
				{
					setcolor(15);
					outtextxy(280,180,"MIDIUM");
					//l=27;
					break;

				}
				else if(ch==13)
				{
					T=10;
					ch=27;
					break;

				}
				else if(ch==27);
				{
					break;
				}
				 delay(10);

			}

		}

		if(l==3)
		{
			setcolor(4);
			outtextxy(286,210,"HIGH");
			while(1)
			{
				if(kbhit)
				{
					ch=getch();
					l=l_test(ch,l);
				}
				if(l==1||l==2)
				{
					setcolor(15);
					outtextxy(286,210,"HIGH");
					//l=27;
					break;

				}
				else if(ch==13)
				{
					T=5;
					ch=27;
					break;


				}
				else if(ch==27);
				{
					break;
				}
				 delay(10);

			}


	      }
		delay(10);

	}
	setcolor(0);
	outtextxy(420,370,"Press Enter to Active");


}



//
int m_test(int I, int c)
{
	if(c==100)
	{
		I++;
		if(I>=6 )
		{
			I=1;
		}
	 }
	 else if(c==117)
	 {
		I--;
		if(I<=0 )
		{
			I=6;
		}
	 }
	 return I;
}

//
/*
void lvl_menu(int c)
{


	setcolor(c);
	settextstyle(1,0,0);
	outtextxy(270,30,"LEVEL");
	settextstyle(0,0,0);
	//setcolor(c);
	outtextxy(280,150,"SIMPLE");
	outtextxy(280,180,"MEDIUM");
	outtextxy(286,210,"HIGH");
	outtextxy(286,240,"BACK");
	outtextxy(420,350,"Press D or U to Select ");
	outtextxy(420,370,"Press Enter to Active");

} */

//

void menu_l(int c)
{
	setcolor(c);
	settextstyle(1,0,0);
	outtextxy(270,50,"MENU");
	settextstyle(0,0,0);
	outtextxy(280,130,"NEW GAME");
	//outtextxy(283,120,"CONTINUE");
	outtextxy(288,170,"LEVEL");
	outtextxy(288,200,"SCORE");
	outtextxy(290,230,"HELP");
	outtextxy(290,260,"EXIT");
	outtextxy(420,330,"Press D or U to Move   ");
	outtextxy(470,350,"UP and Down");
	outtextxy(420,370,"Press Enter to Select");


}

//

int menu()
{
	int i1=0,c=0,ret;
	/*setcolor(15);
	outtextxy(280,90,"NEW GAME");
	outtextxy(283,120,"CONTINU");
	outtextxy(288,150,"LEVEL");
	outtextxy(288,180,"SCORE");
	outtextxy(290,210,"HELP");
	outtextxy(290,240,"EXIT");
	 */
	//getch();
	menu_l(15);
	while(1)
	{
	       //	getch();

		//setbkcolor(8);

		if(kbhit())
		{
		       //fflush(stdin);
		       c=getch();

			i1 = m_test(i1,c);

		}
			if(i1==1)
			{
				int l=0;
				while(l!=1)
				{
					setcolor(4);
					outtextxy(280,130,"NEW GAME");
					if(kbhit())
					{
						//fflush(stdin);
						c=getch();
						ret=c;

						if(c==100||c==117)
						{
							i1 = m_test(i1,c);
							setcolor(15);
							outtextxy(280,130,"NEW GAME");

							break;
						}

						if(ret==13)
						{
							new_g();
							menu_l(0);
							while(l!=1)                                                               //infinite
							{
								k++;
								setcolor(15);
								outtextxy(400,420,"Press x to Exit");
								outtextxy(120,420,"Press P to Pause");
								outtextxy(20,5,"Score : ");

								//drow( i, j, a, b, &h );
								if(drow_s())
								{

									l=1;
									E=1;
									cleardevice();
									//clearviewport();
									setcolor(5);
									line(18,18,getmaxx()-18,18);
									line(18,402,getmaxx()-18,402);
									line(18,18,18,402);
									line(getmaxx()-18,18,getmaxx()-18,402);
								       //	printf("   Score : ");


									break;
								}

								delay(T);
							}
							menu_l(15);

						}


					}
					delay(30);
				}

			}
		       /*	if(i1==2)
			{
				while(1)
				{
					setcolor(4);
					outtextxy(283,120,"CONTINUE");
				       if(kbhit())
					{
						//fflush(stdin);
						c=getch();
						ret=c;
						if(c==100||c==117)
						{
							i1 = m_test(i1,c);
							setcolor(15);
							outtextxy(283,120,"CONTINUE");

							break;
						}

						if(ret==13)
						{
							int l=0;
							if(!ext)
							{
								menu_l(0);
								while(l!=1)                                                               //infinite
								{
									k++;
									setcolor(15);
									outtextxy(400,420,"Press x to Exit");
									outtextxy(120,420,"Press P to Pause");

								//drow( i, j, a, b, &h );
									if(drow_s())
									{

										l=1;
										E=1;
										if(ext)

										{
											new_g();
											ext=0;
										}
										cleardevice();
										setcolor(5);
										line(18,18,getmaxx()-18,18);
										line(18,402,getmaxx()-18,402);
										line(18,18,18,402);
										line(getmaxx()-18,18,getmaxx()-18,402);
										//	printf("   Score : ");

										menu_l(15);
										break;
									}
									delay(10);
								}
							}


							//return i1;
						}


					}
					delay(30);
				}

			}*/
			if(i1==2)
			{
				int l=0;
				while(l!=1)
				{
					setcolor(4);
					outtextxy(288,170,"LEVEL");
					if(kbhit())
					{
						//fflush(stdin);
						c=getch();
						ret=c;
						if(c==100||c==117)
						{
							i1 = m_test(i1,c);
							setcolor(15);
							outtextxy(288,170,"LEVEL");

							break;
						}

						if(ret==13)
						{
							menu_l(0);
							level();
							lvl_menu(0);
							l=1;
							menu_l(15);
							setcolor(15);
							outtextxy(288,170,"LEVEL");

							break;
							//return i1;
						}


					}
					delay(30);
				}

			}
			if(i1==3)
			{
				while(1)
				{
					setcolor(4);
					outtextxy(288,200,"SCORE");
					if(kbhit())
					{
						//fflush(stdin);
						c=getch();
						ret=c;
						if(c==100||c==117)
						{
							i1 = m_test(i1,c);
							setcolor(15);
							outtextxy(288,200,"SCORE");

							break;
						}

						if(ret==13)
						{

							break;
							//return i1;
						}


					}
					delay(30);
				}

			}

			if(i1==4)
			{
				while(1)
				{
					setcolor(4);
					outtextxy(290,230,"HELP");
					if(kbhit())
					{
						//fflush(stdin);
						c=getch();
						ret=c;
						if(c==100||c==117)
						{
							i1 = m_test(i1,c);
							setcolor(15);
							outtextxy(290,230,"HELP");
							break;
						}

						if(ret==13)
						{
							help( 15 );
							//setcolor(0);
							help(0);

						  //	return i1;
						}


					}
					delay(30);
				}

			}
			if(i1==5)
			{
				while(1)
				{
					setcolor(4);
					outtextxy(290,260,"EXIT");

					if(kbhit())
					{
						//fflush(stdin);
						c=getch();

						ret=c;
						if(c==100||c==117)
						{
							i1 = m_test(i1,c);
							setcolor(15);
							outtextxy(290,260,"EXIT");
							break;
						}

						if(ret==13)
						{
							return i1;
						}


					}
					delay(30);
				}

			}

		//}
		//delay(50);
		//getch();
	}



}

//
void help(int clr)
{
	int c=0;
	/*setcolor(0);
	outtextxy(280,90,"NEW GAME");
	outtextxy(283,120,"CONTINU");
	outtextxy(288,150,"LEVEL");
	outtextxy(288,180,"SCORE");
	outtextxy(290,210,"HELP");
	outtextxy(290,240,"EXIT");
	*/
	menu_l(c);

	do
	{

		if(kbhit())
		{
			c=getch();
		}
		setcolor(clr);
		outtextxy(260,50,"HELP  ");

		line(200,100,250,100);
		line(250,100,240,95);
		line(250,100,240,105);
		outtextxy(300,100,"To Move Right  ");

		line(200,150,250,150);
		line(200,150,210,155);
		line(200,150,210,145);
		outtextxy(300,150,"To Move Left  ");

		line(230,180,230,230);
		line(230,180,225,190);
		line(230,180,235,190);
		outtextxy(300,205,"To Move UP  ");

		line(230,260,230,310);
		line(230,310,225,300);
		line(230,310,235,300);
		outtextxy(300,280,"To Move Down  ");

		outtextxy(30,390,"Press Enter to Back  ");



	}while(c!=13 && clr!=0);

	menu_l(15);
	/*setcolor(15);
	outtextxy(280,90,"NEW GAME");
	outtextxy(283,120,"CONTINU");
	outtextxy(288,150,"LEVEL");
	outtextxy(288,180,"SCORE");
	outtextxy(290,210,"HELP");
	outtextxy(290,240,"EXIT");
	*/

}



//
void main()
{
	int gd  , gm,ch ;
	//printf(" By chandan");

	gd = gm = DETECT;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	//menu_l(0);



	setcolor(5);
	line(18,18,getmaxx()-18,18);
	line(18,402,getmaxx()-18,402);
	line(18,18,18,402);
	line(getmaxx()-18,18,getmaxx()-18,402);
	//printf("   Score : ");
	setbkcolor(0);
	menu();
	//lvl_menu(15);
	//getch();
       /*	while(1)                                                               //infinite
	{
		k++;
		setcolor(15);
		outtextxy(400,420,"Press x to Exit");
		outtextxy(120,420,"Press P to Pause");
		//drow( i, j, a, b, &h );
		if(drow_s())
		{
			E=1;
			break;
		}
		delay(10);
	}*/

		//cleardevice();



}