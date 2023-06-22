#pragma once

#include "Event.h"

namespace Core 
{
	class WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(int width, int height) : Event("WindowResizedEvent", EventType::WINDOWS_RESIZED_EVENT), width(width), height(height) {}

		std::string format() const override
		{
			std::string formatted = name + ": " + std::to_string(width) + "." + std::to_string(height);
			return formatted;
		}

	private:
		int width, height;
	};


	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() : Event("WindowCloseEvent", EventType::WINDOWS_CLOSED_EVENT) {}

		std::string format() const override
		{
			return name;
		}
	};
}