#include "raylib.h"
#include <ctime>



// Velka cast tohto kodu je uvedena ako expamle na stranke kniznice raylib
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int sirkaOkna = 800;
    int vyskaOkna = 450;
    int polomer = 50;          // polomer cerveneho kruhu

    // biely obdlznik v strede okna
    int obdlznikSirka = 300;
    int obdlznikVyska = 200;
    int obdlznikX = (sirkaOkna - obdlznikSirka) / 2;   
    int obdlznikY = (vyskaOkna - obdlznikVyska) / 2;


    int stredX = sirkaOkna / 2;
    int stredY = vyskaOkna / 2;

    InitWindow(sirkaOkna, vyskaOkna, "raylib [core] example - input keys");

    Vector2 ballPosition;

    SetRandomSeed(time(NULL));          
    int roh = GetRandomValue(0, 3);     

    if (roh == 0)       // lavy horny
    {
        ballPosition.x = polomer;
        ballPosition.y = polomer;
    }
    else if (roh == 1)  // pravy horny
    {
        ballPosition.x = sirkaOkna - polomer;
        ballPosition.y = polomer;
    }
    else if (roh == 2)  // lavy dolny
    {
        ballPosition.x = polomer;
        ballPosition.y = vyskaOkna - polomer;
    }
    else                // pravy dolny
    {
        ballPosition.x = sirkaOkna - polomer;
        ballPosition.y = vyskaOkna - polomer;
    }

    bool vyhra = false; 

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            if (vyhra == false) {
            //hranice
            if (ballPosition.x > sirkaOkna - polomer) ballPosition.x -= 2.0f;
            if (ballPosition.y > vyskaOkna - polomer) ballPosition.y -= 2.0f;
            if (ballPosition.x < 0 + polomer) ballPosition.x += 2.0f;
            if (ballPosition.y < 0 + polomer) ballPosition.y += 2.0f;
            // Update
            //----------------------------------------------------------------------------------
            if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
            if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
            if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
            if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;
            //----------------------------------------------------------------------------------

            // --- KONTROLA, CI SME V STREDE ---
                // dovolime odchylku 3 pixely, lebo sa hybeme po 2 pixeloch
                if (ballPosition.x >= stredX - 3 && ballPosition.x <= stredX + 3 &&
                    ballPosition.y >= stredY - 3 && ballPosition.y <= stredY + 3)
                {
                    ballPosition.x = stredX;      // dorovname presne do stredu
                    ballPosition.y = stredY;
                    vyhra = true;
                }
            }
            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();

                ClearBackground(DARKGRAY);                                                 // pozadie okna
                DrawRectangle(obdlznikX, obdlznikY, obdlznikSirka, obdlznikVyska, WHITE);  // biely obdlznik
                DrawCircleV(ballPosition, polomer, RED);                                   // cerveny kruh

                DrawText("Sipkami dostan cerveny kruh do stredu bieleho obdlznika", 10, 10, 20, RAYWHITE);

                if (vyhra == true)
                {
                    DrawText("Vyhral si!", 330, 400, 30, GREEN);
                }

            EndDrawing();
            //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}



