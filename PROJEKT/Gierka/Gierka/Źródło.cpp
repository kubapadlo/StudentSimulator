#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <Windows.h>

#pragma warning(disable : 4996)

#include "Player.h"
#include "platform.h"
#include "Collider.h"
#include "Mainmenu.h"
#include "Enemy.h"
#include "Math.h"
#include "Images.h"
#include "SpriteClass.h"
#include "BiedronkaColission.h"
#include "Volume.h"

using namespace sf;

void ResizeWindow(RenderWindow& window, View& view)
{
	float aspectratio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(aspectratio * float(view.getSize().y), float(view.getSize().y));
}

int main()
{
	float health = 100;
	int sleep = 100;
	int hunger = 100;
	int money = 20;
	int knowledge = 0;

	Music music;
	music.openFromFile("muzyka.wav");

	View view(Vector2f(640.0f, 480.0f), Vector2f(1280.0f, 960.0f));	
	//View menuview(Vector2f(640.0f, 480.0f), Vector2f(1280.0f, 960.0f));

	Texture skele;
	skele.loadFromFile("animationsprites.png");

	Texture enemytexture;
	enemytexture.loadFromFile("kibol.png");

	Texture bullettexture;
	bullettexture.loadFromFile("butelka.png");

	RectangleShape progressbar;
	progressbar.setFillColor(Color::Green);
	progressbar.setOutlineThickness(2);
	progressbar.setOutlineColor(Color::Black);
	progressbar.setPosition(Vector2f(234.0f, 21.0f));

	Player player(&skele, Vector2u(9,3), 0.15f, 100.0f);

	std::vector<CircleShape> bullets;

	bullets.reserve(100);
	float bulletspeed = 5.0f;
	Vector2f direction;

	std::vector<Vector2f> directions;
	
	float deltatime = 0.0f;
	Clock clock;
		
	RenderWindow menu(VideoMode(1280, 960), "Main Menu", Style::Resize | Style::Close);
	menu.setFramerateLimit(60);
	Mainmenu mainmenu(1280.0f, 960.0f);
	Volume volume(1280.0f, 960.0f);

	Font font;
	if (!font.loadFromFile("upheavtt.ttf"))
	{
		std::cout << "Cant load font";
	}

	SpriteClass statsbox("statsback.png", Vector2f(920.0f, 0.0f));
	//statsbox.setscale(0.3f, 0.3f);

	SpriteClass Olimp("Olimp.png", Vector2f(200.0f, 400.0f));
	Olimp.setscale(4.0f, 5.0f);

	SpriteClass Biedronka("biedronka.png", Vector2f(500.0f, 30.0f));
	Biedronka.setscale(3.0f, 3.0f);

	SpriteClass B4("b4.png", Vector2f(900.0f, 400.0f));
	B4.setscale(3.0f, 3.0f);

	Images menubackground("menubackground.png");
	Images olimpRoom("Olimproom.png");
	Images b4room("B4sala.png");
	Images Inbiedronka("Inbiedronkaceny.png");
	Images playwindowback("grass.png");
	Images optionsbackground("optionsback.png");

	sf::Text clockText("", font, 50);
	clockText.setPosition(Vector2f(10.0f, 10.0f));
	clockText.setFillColor(sf::Color::White);
	clockText.setOutlineColor(Color::Black);
	clockText.setOutlineThickness(2);


	std::vector<RectangleShape> enemies;
	enemies.reserve(100);
	float enemyspeed = 2.5f;
	bool spawned = false;

	srand(time(NULL));

	while (menu.isOpen())
	{
		Event evnt;
		while (menu.pollEvent(evnt))  //zbiera info o inpucie uzytkownika
		{
			if (evnt.type == Event::Closed)
				menu.close();
			if (evnt.type == Event::Resized)
				ResizeWindow(menu, view);

			if (evnt.type == Event::KeyReleased)
			{
				if (evnt.key.code == Keyboard::Up)
					mainmenu.moveUp();
				if (evnt.key.code == Keyboard::Down)
					mainmenu.moveDown();
				if (evnt.key.code == Keyboard::Return)
				{
					int choice = mainmenu.Pressed();

					if (choice == 0)
					{
						music.play();
						RenderWindow playwindow(VideoMode(1280, 960), "Symulator Studenta", Style::Resize | Style::Close);
						playwindow.setFramerateLimit(60);

						int days = 1;
						int hours = 8;
						int minutes = 0;
						int seconds = 0;

						while (playwindow.isOpen())
						{
							
							deltatime = clock.restart().asSeconds(); //zwraca wartosc timera i zeruje jego wartosc	

							Event evnt;
							while (playwindow.pollEvent(evnt))  //zbiera info o inpucie uzytkownika
							{
								if (evnt.type == Event::Closed)
									playwindow.close();

								else if (evnt.type == Event::Resized)
									ResizeWindow(playwindow, view);

								if (evnt.type == Event::KeyReleased)
								{
									if (evnt.key.code == Keyboard::Space)
									{
										bullets.push_back(CircleShape(10.0f));
										bullets[bullets.size() - 1].setPosition(player.getposition());
										directions.push_back(static_cast<Vector2f>(Mouse::getPosition(playwindow)) - player.getposition());
									}
								}
							}
							// ----------CLOCK----------
							seconds += 10; 
							if (seconds >= 60)
							{
								seconds -= 60;
								minutes++;
								if (hunger == 0)
								{
									if (health > 0)
										health -= 0.1f;
								}
								if (minutes >= 60)
								{
									minutes = 0;
									hours++;
									if ((hunger -= 3) <= 3)
										hunger = 0;
									if (sleep >= 5)
										sleep -= 5;

									if (hours >= 24)
									{
										hours = -(24 - hours);
										days++;
										enemyspeed += 0.2f;
										spawned = false;
									}
								}
							}



							std::stringstream ss;
							ss << std::setw(2) << std::setfill('0') << "DZIEN " << days << "\n"
								<< std::setw(2) << std::setfill('0') << hours << ":00";
							//<< std::setw(2) << std::setfill('0') << minutes << ":"
							//<< std::setw(2) << std::setfill('0') << seconds;

							clockText.setString(ss.str());

							//-------------------------------------------
							if (spawned == false && hours > 19)
							{
								for (int i = 0; i < 15; i++)
								{
									enemies.push_back(RectangleShape(Vector2f(50.0f, 50.0f)));
									enemies[i].setTexture(&enemytexture);
									enemies[i].setPosition(Vector2f(rand() % 1200, rand() % 900));
								}
								spawned = true;
							}

							if (spawned == true && hours > 19)
							{
								for (size_t i = 0; i < enemies.size(); i++)
								{
									Vector2f enemydirection = player.getposition() - enemies[i].getPosition();
									enemydirection = Math::NormalizeVector(enemydirection);
									enemies[i].setScale(1.5f, 1.5f);
									enemies[i].setPosition(enemies[i].getPosition() + enemydirection * enemyspeed);
								}
							}

							if (enemies.size() > 0)
								clockText.setFillColor(Color::Red);
							else
								clockText.setFillColor(Color::White);

							for (int i = 0; i < bullets.size(); i++)
							{
								bullets[i].setTexture(&bullettexture);
								directions[i] = Math::NormalizeVector(directions[i]);
								bullets[i].setPosition(bullets[i].getPosition() + directions[i] * bulletspeed);
							}

							for (int j = 0; j < enemies.size(); j++)
							{
								for (int i = 0; i < bullets.size(); i++)
								{
									if (bullets[i].getGlobalBounds().intersects(enemies[j].getGlobalBounds())) //|| bullets[i].getGlobalBounds().intersects(enemies[1].getGlobalBounds()) || bullets[i].getGlobalBounds().intersects(enemies[2].getGlobalBounds()) )
									{
										bullets.erase(bullets.begin() + i);
										directions.erase(directions.begin() + i);
										enemies.erase(enemies.begin() + j);
										money += 1;
									}
								}
							}
							player.update(deltatime, sleep);

							if (player.getbounds().intersects(Olimp.getbounds()))
							{
								RenderWindow InOlimp(VideoMode(1280, 960), "Olimp", Style::Resize | Style::Close);
								InOlimp.setFramerateLimit(60);

								while (InOlimp.isOpen())
								{
									Event olimpEvent;

									Vector2i mousepos = Mouse::getPosition(InOlimp); //funkcja mouse::getposition zwraca pozycje w intach

									while (InOlimp.pollEvent(olimpEvent))  //zbiera info o inpucie uzytkownika
									{
										if (olimpEvent.type == Event::Closed)
											InOlimp.close();

										if (olimpEvent.type == sf::Event::MouseButtonReleased)
										{
											if (olimpEvent.mouseButton.button == sf::Mouse::Left)
											{
												if (mousepos.x > 900 && mousepos.x < 1000 && mousepos.y > 400 && mousepos.y < 520)
												{
													if (health > 0)
													{
														sleep -= 10;
														hours += 1;
													}
												}
												if (mousepos.x > 150 && mousepos.x < 500 && mousepos.y > 650 && mousepos.y < 800)
												{
													sleep = 100;

													if ((hours += 8) > 24)
													{
														days++;
														enemyspeed += 0.2f;
														spawned = false;
													}

													if (hours >= 24)
														hours = -(24 - hours);
												}
												if (mousepos.x > 0 && mousepos.x < 150 && mousepos.y > 40 && mousepos.y < 440)
													InOlimp.close();
											}
										}

									}

									// --------CLOCK--------
									seconds += 10; // Increase seconds by 5 (you can adjust this value)
									if (seconds >= 60)
									{
										seconds -= 60;
										minutes++;
										if (hunger == 0)
											health -= 0.2f;

										if (minutes >= 60)
										{
											minutes = 0;
											hours++;
											if ((hunger -= 3) <= 3)
												hunger = 0;
											if (sleep >= 5)
												sleep -= 5;

											if (hours >= 24)
											{
												hours = 0;
												days++;
												enemyspeed += 0.2f;
												spawned = false;
											}
										}
									}

									//------------------


									Text stats;
									stats.setCharacterSize(30);
									stats.setFillColor(Color::Black);
									stats.setFont(font);
									stats.setPosition(Vector2f(970.0f, -1.0f));
									std::stringstream aa;


									aa << "ZDROWIE: " << ceil(health) << "/100\n"
										<< "ZMECZENIE: " << sleep << "/100\n"
										<< "GLOD: " << hunger << "/100\n"
										<< "STAN KONTA: " << money << "zl";
									stats.setString(aa.str());


									InOlimp.clear();
									olimpRoom.draw(InOlimp);
									statsbox.draw(InOlimp);
									InOlimp.draw(stats);
									//InOlimp.draw(clockText);
									InOlimp.display();

								}

								player.setPosition(260.0f, 800.0f); // po wyjscu z budynku(zamknieciu okna) cofa postac przed drzwi

							}

							for (int j = enemies.size() - 1; j >= 0; j--)
							{
								if (player.getbounds().intersects(enemies[j].getGlobalBounds()))
								{
									health -= 5;
									enemies.erase(enemies.begin() + j);
								}
							}

							if (player.getbounds().intersects(Biedronka.getbounds()))
							{
								RenderWindow InBiedronka(VideoMode(1280, 960), "Biedronka", Style::Resize | Style::Close);
								InBiedronka.setFramerateLimit(60);

								while (InBiedronka.isOpen())
								{

									seconds += 10; // Increase seconds by 5 (you can adjust this value)
									if (seconds >= 60)
									{
										seconds -= 60;
										minutes++;
										if (hunger == 0)
											health -= 0.2f;

										if (minutes >= 60)
										{
											minutes = 0;
											hours++;
											if ((hunger -= 3) <= 3)
												hunger = 0;
											if (sleep >= 5)
												sleep -= 5;

											if (hours >= 24)
											{
												hours = -(24 - hours);
												days++;
												enemyspeed += 0.2f;
												spawned = false;
											}
										}
									}

									Event biedronkaEvent;
									Vector2i mousepos3 = Mouse::getPosition(InBiedronka);

									Text textb4;
									textb4.setCharacterSize(25);
									textb4.setFillColor(Color::Black);
									textb4.setFont(font);
									textb4.setPosition(Vector2f(20.0f, 20.0f));
									std::stringstream ssss;
									ssss << "Mouse pos: " << mousepos3.x << "-" << mousepos3.y;

									textb4.setString(ssss.str());

									Text b4stats;
									b4stats.setCharacterSize(30);
									b4stats.setFillColor(Color::Black);
									b4stats.setFont(font);
									b4stats.setPosition(Vector2f(970.0f, -1.0f));
									std::stringstream b4;


									b4 << "ZDROWIE: " << ceil(health) << "/100\n"
										<< "ZMECZENIE: " << sleep << "/100\n"
										<< "GLOD: " << hunger << "/100\n"
										<< "STAN KONTA: " << money << "zl";
									//<<"Mouse pos: " << mousepos3.x << "-" << mousepos3.y;
									b4stats.setString(b4.str());

									while (InBiedronka.pollEvent(biedronkaEvent))  //zbiera info o inpucie uzytkownika
									{
										if (biedronkaEvent.type == Event::Closed)
											InBiedronka.close();
										if (biedronkaEvent.type == sf::Event::MouseButtonReleased)
										{
											if (biedronkaEvent.mouseButton.button == sf::Mouse::Left)
											{
												if (mousepos3.x > 490 && mousepos3.x < 770 && mousepos3.y > 20 && mousepos3.y < 200)
													InBiedronka.close();

												BiedronkaColision::CheckCollision(mousepos3, &hunger, &money);
											}
										}
									}
									InBiedronka.clear();
									Inbiedronka.draw(InBiedronka);
									//InBiedronka.draw(textb4);
									statsbox.draw(InBiedronka);
									InBiedronka.draw(b4stats);
									InBiedronka.display();
								}
								player.setPosition(610.0f, 270.0f);
							}

							if (player.getbounds().intersects(B4.getbounds()))
							{
								RenderWindow InB4(VideoMode(1280, 960), "B4", Style::Resize | Style::Close);
								InB4.setFramerateLimit(60);

								while (InB4.isOpen())
								{

									seconds += 10; 
									if (seconds >= 60)
									{
										seconds -= 60;
										minutes++;
										if (hunger == 0)
											health -= 0.2f;

										if (minutes >= 60)
										{
											minutes = 0;
											hours++;
											if ((hunger -= 3) <= 3)
												hunger = 0;
											if (sleep >= 5)
												sleep -= 5;

											if (hours >= 24)
											{
												hours = -(24 - hours);
												days++;
												enemyspeed += 0.2f;
												spawned = false;
											}
										}
									}
									Event b4Event;

									Vector2i mousepos = Mouse::getPosition(InB4); //funkcja mouse::getposition zwraca pozycje w intach

									while (InB4.pollEvent(b4Event))  //zbiera info o inpucie uzytkownika
									{
										if (b4Event.type == Event::Closed)
											InB4.close();
										if (b4Event.type == sf::Event::MouseButtonReleased)
										{
											if (b4Event.mouseButton.button == sf::Mouse::Left)
											{
												if (mousepos.x > 465 && mousepos.x < 870 && mousepos.y > 120 && mousepos.y < 350)
												{
													if (knowledge < 20 && sleep >= 10 && hunger >= 6)
													{
														knowledge += 1;
														hours += 2;
														hunger -= 6;
														sleep -= 10;
													}
												}

												if (mousepos.x > 80 && mousepos.x < 310 && mousepos.y > 60 && mousepos.y < 415)
													InB4.close();
											}
										}
									}
									Vector2i mousepos2 = Mouse::getPosition(InB4); //funkcja mouse::getposition zwraca pozycje w intach

									Text stats1;
									stats1.setCharacterSize(30);
									stats1.setFillColor(Color::Black);
									stats1.setFont(font);
									stats1.setPosition(Vector2f(970.0f, -1.0f));
									std::stringstream ssss;

									ssss << "ZDROWIE: " << ceil(health) << "/100\n"
										<< "ZMECZENIE: " << sleep << "/100\n"
										<< "GLOD: " << hunger << "/100\n"
										<< "STAN KONTA: " << money << "zl\n";
										//<< "Mouse pos: " << mousepos2.x << "-" << mousepos2.y;
									stats1.setString(ssss.str());

									std::stringstream ss;
									ss << std::setw(2) << std::setfill('0') << "DZIEN " << days << "\n"
										<< std::setw(2) << std::setfill('0') << hours << ":00";
									clockText.setString(ss.str());

									progressbar.setSize(Vector2f(knowledge * 30, 20));

									InB4.clear();
									b4room.draw(InB4);
									InB4.draw(progressbar);
									statsbox.draw(InB4);
									InB4.draw(stats1);
									InB4.draw(clockText);
									InB4.display();
								}
								player.setPosition(1010.0f, 680.0f);
							}
							/*
							RectangleShape progressbar;
							progressbar.setFillColor(Color::Green);
							progressbar.setOutlineThickness(2);
							progressbar.setOutlineColor(Color::Black);
							progressbar.setSize(Vector2f(knowledge * 60, 20));
							progressbar.setPosition(Vector2f(250.0f, 15.0f));
							*/
							Text stats1;
							stats1.setCharacterSize(30);
							stats1.setFillColor(Color::Black);
							stats1.setFont(font);
							stats1.setPosition(Vector2f(970.0f, -1.0f));
							std::stringstream sss;

							sss << "ZDROWIE: " << ceil(health) << "/100\n"
								<< "ZMECZENIE: " << sleep << "/100\n"
								<< "GLOD: " << hunger << "/100\n"
								<< "STAN KONTA: " << money << "zl";
							stats1.setString(sss.str());


							//view.setCenter(player.getposition());

							playwindow.clear(Color::Yellow); //czysci bufer dzieki czemu mamy obraz klatka po klatce

							//Render game objects
							playwindow.setView(view);
							playwindowback.draw(playwindow);
							Olimp.draw(playwindow);
							Biedronka.draw(playwindow);
							B4.draw(playwindow);
							player.draw(playwindow);



							if ((health <= 0) || (knowledge < 20 && days > 5))
							{
								Time time = sf::seconds(5);
								Text endgame;
								endgame.setCharacterSize(120);
								endgame.setPosition(Vector2f(330.0f, 250.0f));
								endgame.setString("KONIEC GRY");
								endgame.setFont(font);
								endgame.setColor(Color::Red);
								playwindow.draw(endgame);
								enemies.clear();
							}

							if (knowledge == 20)
							{
								Time time = sf::seconds(5);
								Text endgame;
								endgame.setCharacterSize(120);
								endgame.setPosition(Vector2f(200.0f, 250.0f));
								endgame.setString("ZDALES KOLOSA");
								endgame.setFont(font);
								endgame.setColor(Color::Green);
								playwindow.draw(endgame);
								enemies.clear();
							}


							for (int i = 0; i < bullets.size(); i++)
							{
								playwindow.draw(bullets[i]);
							}


							for (int i = 0; i < enemies.size(); i++)
							{
								playwindow.draw(enemies[i]);
							}


							//bullet.draw(playwindow, drawable);

							//Render interface
							playwindow.setView(playwindow.getDefaultView());
							statsbox.draw(playwindow);
							playwindow.draw(stats1);
							playwindow.draw(clockText);

							//platform.draw(playwindow);
							playwindow.display();


						}
					}
					if (choice == 1)
					{
						RenderWindow optionswindow(VideoMode(1280, 960), "Options", Style::Resize | Style::Close);

						optionswindow.setFramerateLimit(60);
						sf::Text clockText("", font, 50);
						clockText.setFillColor(sf::Color::Black);
						clockText.setPosition(Vector2f(20.0f, 5.0f));
						

						while (optionswindow.isOpen())
						{
							Vector2i mousepose = Mouse::getPosition(optionswindow);
							Event oevent;
							while (optionswindow.pollEvent(oevent))
							{
								if (oevent.type == Event::Closed)
								{
									optionswindow.close();
								}
								if (oevent.type == Event::KeyReleased)
								{
									if (oevent.key.code == Keyboard::Right)
										volume.moveRight();
									if (oevent.key.code == Keyboard::Left)
										volume.moveLeft();
									if (oevent.key.code == Keyboard::Return)
									{
										int volumechoice = volume.Pressed();

										if (volumechoice == 0)
											music.setVolume(0);
										if (volumechoice == 1)
											music.setVolume(25);
										if (volumechoice == 2)
											music.setVolume(50);
										if (volumechoice == 3)
											music.setVolume(75);
										if (volumechoice == 4)
											music.setVolume(100);
									}
								}
								if (oevent.type == sf::Event::MouseButtonReleased)
								{
										if (oevent.mouseButton.button == sf::Mouse::Left)
										{
											if (mousepose.x > 378 && mousepose.x < 437 && mousepose.y > 748 && mousepose.y < 796)
												player.setcolor(Color::Black);
											if (mousepose.x > 437 && mousepose.x < 492 && mousepose.y > 748 && mousepose.y < 796)
												player.setcolor(Color::Blue);
											if (mousepose.x > 492 && mousepose.x < 547 && mousepose.y > 748 && mousepose.y < 796)
												player.setcolor(Color::Cyan);
											if (mousepose.x > 547 && mousepose.x < 596 && mousepose.y > 748 && mousepose.y < 796)
												player.setcolor(Color::Green);
											if (mousepose.x > 596 && mousepose.x < 649 && mousepose.y > 748 && mousepose.y < 796)
												player.setcolor(Color::Magenta);
											if (mousepose.x > 649 && mousepose.x < 706 && mousepose.y > 748 && mousepose.y < 796)
												player.setcolor(Color::Red);
											if (mousepose.x > 706 && mousepose.x < 763 && mousepose.y > 748 && mousepose.y < 796)
												player.setcolor(Color::Transparent);
											if (mousepose.x > 763 && mousepose.x < 842 && mousepose.y > 748 && mousepose.y < 796)
												player.setcolor(Color::White);
											if (mousepose.x > 842 && mousepose.x < 921 && mousepose.y > 748 && mousepose.y < 796)
												player.setcolor(Color::Yellow);
										}
								}
							}

						
							std::time_t currentTime = std::time(nullptr);
							std::tm* time = std::localtime(&currentTime);
							std::ostringstream oss;
							oss << std::put_time(time, "%H:%M:%S");
							clockText.setString(oss.str());

							optionswindow.clear(Color::Black);
							optionsbackground.draw(optionswindow);
							optionswindow.draw(clockText);
							volume.draw(optionswindow);
							optionswindow.display();
						}


					}
					if (choice == 2)
					{
						menu.close();
					}
				}
			}
			menu.clear();
			menubackground.draw(menu);
			mainmenu.draw(menu);
			menu.display();
		}
	}

	return 0;
}