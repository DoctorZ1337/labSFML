#pragma once
#include <string>
#include <Figures.hpp>

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
			int r = rand() % 100 + 10;
			int x = rand() % (m_width - 2 * r) + r;
			int y = rand() % (m_height - 2 * r) + r;
			int c_v = rand() % 360;
			float alfa = 5 + rand() % 2;
			m_c.setupCircle(x, y, r, c_v, alfa);

			// Настройка параметров квадрата
			int side = rand() % 80 + 20;
			int s_v = rand() % 360;
			float beta = 5 + rand() % 2;
			int s_x = rand() % (m_width - 2 * side) + side;
			int s_y = rand() % (m_height - 2 * side) + side;
			m_s.setupSquare(s_x, s_y, side, s_v, beta);

			// Настройка параметров треугольника
			int t_a = rand() % 80 + 20;
			int t_v = rand() % 360;
			float gamma = 5 + rand() % 2;
			int t_x = rand() % (m_width - 2 * t_a) + t_a;
			int t_y = rand() % (m_height - 2 * t_a) + t_a;
			m_t.setupTriangle(t_x, t_y, t_a, t_v, gamma);
		}

		void touchBorder(Circle& obj) {
			float x = obj.X();
			float y = obj.Y();
			float r = obj.R();

			if (x + r >= m_width || x - r <= 0) {
				obj.Alfa(pi - obj.Alfa());
				obj.setRandomColor();
			}

			if (y + r >= m_height || y - r <= 0) {
				obj.Alfa(2 * pi - obj.Alfa());
				obj.setRandomColor();
			}

		}

		void touchBorder(Square& obj) {
			float x = obj.X();
			float y = obj.Y();
			float side = obj.Side();

			if (x + side / 2 >= m_width) {
				// Столкновение с правой границей
				obj.Beta(pi - obj.Beta());
				obj.setRandomColor();
			}

			if (x - side / 2 <= 0) {
				// Столкновение с левой границей
				obj.Beta(pi - obj.Beta());
				obj.setRandomColor();
			}

			if (y + side / 2 >= m_height) {
				// Столкновение с нижней границей
				obj.Beta(-obj.Beta());
				obj.setRandomColor();
			}

			if (y - side / 2 <= 0) {
				// Столкновение с верхней границей
				obj.Beta(-obj.Beta());
				obj.setRandomColor();
			}
		}

		void touchBorder(Triangle& obj) {
			float x = obj.X();
			float y = obj.Y();
			float a = obj.A();

			if (x + a / 2.0f >= m_width) {
				// Столкновение с правой границей
				obj.Gamma(pi - obj.Gamma());
				obj.setRandomColor();
			}

			if (x - a / 2.0f <= 0) {
				// Столкновение с левой границей
				obj.Gamma(pi - obj.Gamma());
				obj.setRandomColor();
			}

			if (y + a / 2.0f >= m_height) {
				// Столкновение с нижней границей
				obj.Gamma(2.0f * pi - obj.Gamma());
				obj.setRandomColor();
			}

			if (y - a / 2.0f <= 0) {
				// Столкновение с верхней границей
				obj.Gamma(2.0f * pi - obj.Gamma());
				obj.setRandomColor();
			}
		}

		void LifeCycle() {
			sf::Clock clock;

			float beginTime = 0.0f;
			float delay = 2.0f;

			while (beginTime < delay && m_window.isOpen()) {
				sf::Event event;
				while (m_window.pollEvent(event)) {
					if (event.type == sf::Event::Closed)
						m_window.close();
				}

				float dt = clock.getElapsedTime().asSeconds();
				beginTime += dt;
				clock.restart();

				m_window.clear();
				m_window.draw(m_c.getCircle());
				m_window.draw(m_s.getSquare());
				m_window.draw(m_t.getTriangle());
				m_window.display();
			}

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