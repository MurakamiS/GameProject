#pragma once

class Board;
class Game;
class TurnSprite;

class Player:public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	int SousaFlag=1;//����t���O�@�P������\�A�O������s�\
	int turn = -1; //���݂̃^�[���@1�����A-1����
	int cursorX=3;
	int cursorY=3;
	int time = 0;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	Board* m_board = nullptr;
	Game* m_game = nullptr;
	TurnSprite* m_turnsp =nullptr;
	CVector3 m_position = CVector3::Zero;




	enum EnAnimationClip {
		enAnimationClip_solrun,	//�ҋ@�A�j���[�V�����B
		//enAnimationClip_run,	//����A�j���[�V�����B
		//enAnimationClip_walk,	//�����A�j���[�V�����B
		enAnimationClip_Num,	//�A�j���[�V�����N���b�v�̐��B
	};
	prefab::CSkinModelRender* m_skinModelRender1 = nullptr;
	CAnimationClip m_animClips[enAnimationClip_Num];	//�A�j���[�V�����N���b�v�B
};

