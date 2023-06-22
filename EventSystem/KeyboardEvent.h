#pragma once
#include "Event.h"

namespace Core
{
	class KeyPressedEvent : public Event
	{
	public:
		KeyPressedEvent(int key) : Event("KeyPressedEvent", EventType::KEY_PRESSED_EVENT), key(key) {}

		std::string format() const override
		{
			std::string formatted = name + ": " + (char)key;
			return formatted;
		}

	private:
		int key;
	};

	class KeyReleasedEvent : public Event
	{
	public:
		KeyReleasedEvent(int key) : Event("KeyReleasedEvent", EventType::KEY_RELEASED_EVENT), key(key) {}

		std::string format() const override
		{
			std::string formatted = name + ": " + (char)key;
			return formatted;
		}

	private:
		int key;
	};

	class KeyRepeatEvent : public Event
	{
	public:
		KeyRepeatEvent(int key) : Event("KeyRepeatEvent", EventType::KEY_REPEATED_EVENT), key(key) {}

		std::string format() const override
		{
			std::string formatted = name + ": " + (char)key;
			return formatted;
		}

	private:
		int key;
	};

}