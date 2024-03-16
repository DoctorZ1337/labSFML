#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace sz
{

	// Круг
	class Circle
	{
		float m_r;
		float m_x, m_y;
		float m_v;
		float m_alfa;
		sf::CircleShape m_shape;
	public:
		Circle() = default;

		Circle(float x, float y, float r, float v, float alfa) {
			setupCircle(x, y, r, v, alfa);
		}

		void setupCircle(float x, float y, float r, float v, float alfa) {
			m_x = x;
			m_y = y;
			m_r = r;
			m_v = v;
			m_alfa = alfa;
			m_shape.setOrigin(m_r, m_r);
			m_shape.setRadius(m_r);
			m_shape.setPosition(m_x, m_y);
			m_shape.setFillColor(sf::Color::Green);
		}

		void setRandomColor() {
			m_shape.setFillColor(sf::Color::Color(rand() % 256, rand() % 256, rand() % 256, 255));
		}

		sf::CircleShape getCircle() {
			return m_shape;
		}

		void setX(float newX) {
			m_x = newX;
		}

		void setY(float newY) {
			m_y = newY;
		}

		float X() { return m_x; }
		float Y() { return m_y; }
		float R() { return m_r; }
		float Alfa() { return m_alfa; }
		float Vx() { return m_v * cos(m_alfa); };
		float Vy() { return m_v * sin(m_alfa); }

		void Alfa(float alfa) {
			m_alfa = alfa;
		}

		void Move(float dt) {
			float vx = m_v * cos(m_alfa);
			float vy = m_v * sin(m_alfa);
			m_x += vx * dt;
			m_y += vy * dt;
			m_shape.setPosition(m_x, m_y);
		}

	};

	// Квадрат
	class Square {
		float m_side;
		float m_x, m_y;
		float m_v;
		float m_beta;
		sf::RectangleShape m_shape;

	public:
		Square() = default;

		Square(float x, float y, float side, float v, float beta) {
			setupSquare(x, y, side, v, beta);
		}

		void setupSquare(float x, float y, float side, float v, float beta) {
			m_x = x;
			m_y = y;
			m_side = side;
			m_v = v;
			m_beta = beta;
			m_shape.setOrigin(m_side / 2, m_side / 2);
			m_shape.setSize(sf::Vector2f(m_side, m_side));
			m_shape.setPosition(m_x, m_y);
			m_shape.setFillColor(sf::Color::Blue);
		}

		void setRandomColor() {
			m_shape.setFillColor(sf::Color::Color(rand() % 256, rand() % 256, rand() % 256, 255));
		}

		sf::RectangleShape getSquare() {
			return m_shape;
		}

		void setX(float newX) {
			m_x = newX;
		}

		void setY(float newY) {
			m_y = newY;
		}

		float X() { return m_x; }
		float Y() { return m_y; }
		float Side() { return m_side; }
		float Beta() { return m_beta; }
		void Beta(float beta) {
			m_beta = beta;
		}

		void Move(float dt) {
			float vx = m_v * cos(m_beta);
			float vy = m_v * sin(m_beta);
			m_x += vx * dt;
			m_y += vy * dt;
			m_shape.setPosition(m_x, m_y);
		}
	};

	// Равнобедренный треугольник
	class Triangle
	{
		float m_a;
		float m_x, m_y;
		float m_v;
		float m_gamma;
		sf::ConvexShape m_shape;

	public:
		Triangle() = default;

		Triangle(float x, float y, float a, float v, float gamma)
		{
			setupTriangle(x, y, a, v, gamma);
		}

		void setupTriangle(float x, float y, float a, float v, float gamma)
		{
			m_x = x;
			m_y = y;
			m_a = a;
			m_v = v;
			m_gamma = gamma;

			m_shape.setPointCount(3);
			m_shape.setPoint(0, sf::Vector2f(-m_a / 2, -m_a / 2));
			m_shape.setPoint(1, sf::Vector2f(m_a / 2, -m_a / 2));
			m_shape.setPoint(2, sf::Vector2f(0, m_a / 2));

			m_shape.setOrigin(0, 0);
			m_shape.setPosition(m_x, m_y);
			m_shape.setFillColor(sf::Color::Red);
		}

		void setRandomColor() {
			m_shape.setFillColor(sf::Color::Color(rand() % 256, rand() % 256, rand() % 256, 255));
		}

		sf::ConvexShape getTriangle()
		{
			return m_shape;
		}

		void setX(float newX) {
			m_x = newX;
		}

		void setY(float newY) {
			m_y = newY;
		}

		float X() { return m_x; }
		float Y() { return m_y; }
		float A() { return m_a; }
		float Gamma() { return m_gamma; }

		void Gamma(float gamma)
		{
			m_gamma = gamma;
		}

		void Move(float dt)
		{
			float vx = m_v * cos(m_gamma);
			float vy = m_v * sin(m_gamma);
			m_x += vx * dt;
			m_y += vy * dt;
			m_shape.setPosition(m_x, m_y);
		}
	};
}