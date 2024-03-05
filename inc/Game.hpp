#pragma once
#include <string>

namespace sz
{
	const float pi = acos(-1);

	class Game {
		int m_width;
		int m_height;
		std::string m_capture;
		sz::Circle m_c;
		sz::Square m_s;
		sz::Triangle m_t;
		sf::RenderWindow m_window;

	public:
		Game(int width, int height, const std::string& capture) {
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void setupGame() {
			// Создание окна
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			srand(time(0));

			// Настройка параметров круга
			int r = rand() % 100 + 1;
			int x = rand() % (1600 - 2 * r) + r;
			int y = rand() % (900 - 2 * r) + r;
			int c_v = rand() % 50 + 10;
			float alfa = rand() % 7;
			m_c.setupCircle(x, y, r, c_v, alfa);

			// Настройка параметров квадрата
			int side = rand() % 80 + 20;
			int s_v = rand() % 50 + 10;
			float beta = rand() % 360;
			int s_x = rand() % (1600 - 2 * side) + side;
			int s_y = rand() % (900 - 2 * side) + side;
			m_s.setupSquare(s_x, s_y, side, s_v, beta);

			// Настройка параметров треугольника
			int t_base = rand() % 80 + 20;
			int t_height = rand() % 80 + 20;
			int t_v = rand() % 50 + 10;
			float gamma = rand() % 360;
			int t_x = rand() % (1600 - 2 * t_base) + t_base;
			int t_y = rand() % (900 - 2 * t_height) + t_height;
			m_t.setupTriangle(t_x, t_y, t_base, t_height, t_v, gamma);
		}

		void touchBorder(Circle& obj) {
			float x = obj.X();
			float y = obj.Y();
			float r = obj.R();

			if (x + r >= m_width || x - r <= 0) {
				obj.Alfa(pi - obj.Alfa());
			}

			if (y + r >= m_height || y - r <= 0) {
				obj.Alfa(2 * pi - obj.Alfa());
			}

		}

		void touchBorder(Square& obj) {
			float x = obj.X();
			float y = obj.Y();
			float side = obj.Side();

			if (x + side / 2 >= m_width) {
				// Столкновение с правой границей
				obj.Beta(180 - obj.Beta());
			}

			if (x - side / 2 <= 0) {
				// Столкновение с левой границей
				obj.Beta(180 - obj.Beta());
			}

			if (y + side / 2 >= m_height) {
				// Столкновение с нижней границей
				obj.Beta(-obj.Beta());
			}

			if (y - side / 2 <= 0) {
				// Столкновение с верхней границей
				obj.Beta(-obj.Beta());
			}
		}

		void touchBorder(Triangle& obj) {
			float x = obj.X();
			float y = obj.Y();
			float base = obj.Base();
			float height = obj.Height();

			if (x + base / 2.0f >= m_width) {
				// Столкновение с правой границей
				obj.Gamma(pi - obj.Gamma());
			}

			if (x - base / 2.0f <= 0) {
				// Столкновение с левой границей
				obj.Gamma(pi - obj.Gamma());
			}

			if (y + height / 2.0f >= m_height) {
				// Столкновение с нижней границей
				obj.Gamma(2.0f * pi - obj.Gamma());
			}

			if (y - height / 2.0f <= 0) {
				// Столкновение с верхней границей
				obj.Gamma(2.0f * pi - obj.Gamma());
			}
		}

		void LifeCycle() {
			sf::Clock clock;
			
			while (m_window.isOpen())
			{
				// Обработка событий
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();
				}

				// Логика
				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				// Перемещение шарика
				m_c.Move(dt);
				touchBorder(m_c);

				// Перемещение квадрата
				m_s.Move(dt);
				touchBorder(m_s);

				// Перемещение треугольника
				m_t.Move(dt);
				touchBorder(m_t);

				// Отображение
				m_window.clear();
				m_window.draw(m_c.getCircle());
				m_window.draw(m_s.getSquare());
				m_window.draw(m_t.getTriangle());
				m_window.display();
			}

		}
	};
}