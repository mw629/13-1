#include <Novice.h>
#include "Enemy.h"

const char kWindowTitle[] = "LC1A_27_ワタナベ_マサト";

bool Enemy::isAlive;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Enemy* enemy1 = new Enemy();
	Enemy* enemy2 = new Enemy();

	enemy2->SetPosX(600);
	enemy1->isAlive=true;

	int playerPosX = 0;
	int playerPosY = 0;
	int playerRadius = 100;

	int bulletPosX = 0;
	int bulletPosY = 0;
	int bulletRadius = 50;

	bool isShot = false;



	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		if (keys[DIK_W])
		{
			playerPosY -= 10;
		}
		if (keys[DIK_S])
		{
			playerPosY += 10;
		}
		if (keys[DIK_A])
		{
			playerPosX -= 10;
		}
		if (keys[DIK_D])
		{
			playerPosX += 10;
		}
		if (keys[DIK_SPACE])
		{
			isShot = true;
		}

		if (!isShot)
		{
			bulletPosY = playerPosY;
			bulletPosX = playerPosX;
		}
		if (isShot)
		{
			bulletPosY -= 10;
		}
		if (bulletPosY < 0)
		{
			isShot = false;
		}
		

		enemy1->UpDate(keys, bulletPosX, bulletPosY, bulletRadius, isShot);
		enemy2->UpDate(keys, bulletPosX, bulletPosY, bulletRadius, isShot);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::DrawEllipse(playerPosX, playerPosY, playerRadius, playerRadius, 0, 0xFFFFFFff, kFillModeSolid);
		if (isShot)
		{
			Novice::DrawEllipse(bulletPosX, bulletPosY, bulletRadius, bulletRadius, 0, 0x00FF00ff, kFillModeSolid);
		}

		enemy1->Draw();
		enemy2->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
