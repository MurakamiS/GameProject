#include "stdafx.h"
#include "Count.h"
#include "Player.h"
#include "Animation2.h"
Count::Count()
{
}

Count::~Count()
{
}

bool Count::Start() {

	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			Banmen[a][b] = 0;
		}
	}
	m_player = FindGO<Player>("Player");
	
	return true;
}

void Count::Update() {

	if (Pad(0).IsTrigger(enButtonStart) || Pad(1).IsTrigger(enButtonStart))
	{
		int a = m_player->cursorX;
		int b = m_player->cursorY;

		if (m_player->turn == 1) {
			ten1 = 1;
			ten2 = 5;
			ten3 = -2;
		}
		else if (m_player->turn == -1) {
			ten1 = -1;
			ten2 = -5;
			ten3 = 2;
		}

		Banmen[a + 1][b + 1] += ten2;

		/*if (a == 0) {
		Banmen[a + 2][b+1] += ten1;

		}
		if (a == 7)
		{
			Banmen[a-2][b+1] += ten1;

		}

		if (b == 0)
		{
			Banmen[a+1][b + 2] += ten1;

		}
		if (b == 7)
		{
			Banmen[a+1][b - 2] += ten1;
			*/
			//}
		if (a >= 0 && a <= 7) {
			Banmen[a][b + 1] += ten1;
			Banmen[a + 2][b + 1] += ten1;

		}
		if (b >= 0 && b <= 7) {
			/*Banmen[a+1][b + 2] += ten1;
			Banmen[a+1][b - 2] += ten1;*/
			Banmen[a + 1][b] += ten1;
			Banmen[a + 1][b + 2] += ten1;
		}

	/*	for (int s = 0; s < 10; s++) {
			for (int t = 0; t < 10; t++) {
				if (Banmen[s][t] == 2)
					Banmen[s][t] = 1;

				if (Banmen[s][t] == 4 || 6)
					Banmen[s][t] = 5;

				if (Banmen[s][t] == -2)
					Banmen[s][t] = -1;

				if (Banmen[s][t] == -4 || -6)
					Banmen[s][t] = -5;
			}
		}*/
		 BanmenGoukei = Banmen[a + 1][b] + Banmen[a][b + 1] + Banmen[a + 1][b + 2] + Banmen[a + 2][b + 1];
		// if (BanmenGoukei == (2 || -2))���̏���������2||-2�������1�ɂȂ��Ė]��ł��錋�ʂɂ͂Ȃ�Ȃ�BanmenGoukei==1���ď����Ă���̂ƈꏏ�@
		if (BanmenGoukei == 2||BanmenGoukei==-2) {
			//if(Banmen[a+1][b+1]==(5||-5)){
			NewGO<Animation2>(0, "animation2");

			BanmenGoukei = 0;

		//   ||  ������g����������NewGO�����B
		//if (Banmen[a][b] == ten2) {
		////	���R�����g�A�E�g������NewGO����Ȃ����炱���ł����Ăяo���ĂȂ��B
		//	NewGO<Animation2>(0, "animation2");
		//}
		}
	}
}
//////////////////////////////////
//����ł������Ȃ�ނ�ɂ�����ł����Ƃ���������Banmen�傫������񂶂�Ȃ��Ċ֐�����΂����񂷂�Ⴆ��

void SetMap(int a, int b,int c)//a��b�����W,c���_��
{
	Banmen[a][b] += c;
}
//������Ȋ����̂���w�b�_�[�ɂ����Ƃ���
SetMap(a, b, 5);//�������Ƃ���
if (b > 0)SetMap(a, b - 1, 0);//��
if (b < 7)SetMap(a, b + 1, 1);//��
if (a > 0)SetMap(a - 1, b, 2);//��
if (a < 7)SetMap(a + 1, b, 3);//��
//cpp�ɂ���Ȋ����ɂ���
//�{�[�h����R�s�y�������������炱��ł͓����񂯂ǂ��̏���������ԒP���ɒ[�����̖ʓ|�ȓz�������Ă����͂��@�Ⴆ��if (b > 0)�̂�͈�ԏ�̗�ɂ�����
//���삵�܂���ق��̂�����̕����Ƀ}�X���Ȃ������瓮�삵�Ȃ�
//Board�̔z�u�����݂��炾�������킩��͂��@����switch������߂�ǂ��������ǂǂ����̂��[�񂩂݂Ă邾��������

//bool�^�̍��p�̂��(2||-2)�����ꂪbool�^�ɂȂ��Ă�̂���� https://msdn.microsoft.com/ja-jp/library/f355wky8.aspx 
//����m�F���Ă܂��񂪂�΂�@���̕ӃR�����g�A�E�g����