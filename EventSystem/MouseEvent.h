#pragma once
#include "Event.h"

namespace Core
{
	class MouseMovedEvent : public Event
	{
	public:

		std::string format() const override
		{
			std::string formatted = name + ": " + std::to_string(x) + "." + std::to_string(y);
			return formatted;
		}

		MouseMovedEvent(int x, int y) : Event("MouseMoveEvent", EventType::MOUSE_MOVED_EVENT), x(x), y(y) {}

	private:

		int x, y;

	};


	class MouseScrollEvent : public Event
	{
	
	public:
		MouseScrollEvent(int offset) : Event("MouseScrollEvent", EventType::MOUSE_SCROLLED_EVENT), offset(offset) {}

		std::string format() const override
		{
			std::string formatted = "";
			return (offset < 0) ? formatted = name + ": " + "to bottom" : formatted = name + " : " + "to top";
		}

	private:
		int offset;

	};


	class MouseButtonPressed : public Event
	{
	public:
		MouseButtonPressed(int button) : Event("MouseButtonPressed", EventType::MOUSE_BUTTON_PRESSED_EVENT), button(button) {}

		std::string format() const override
		{
			std::string formatted = name + ": " + std::to_string(button);
			return formatted;
		}
	private:
		int button;
	};


	class MouseButtonReleased : public Event
	{
	public:
		MouseButtonReleased(int button) : Event("MouseButtonReleased", EventType::MOUSE_BUTTON_RELEASED_EVENT), button(button) {}

		std::string format() const override
		{
			std::string formatted = name + ": " + std::to_string(button);
			return formatted;
		}
	private:
		int button;
	};
}