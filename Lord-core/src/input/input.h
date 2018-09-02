#pragma once

#include <SDL/SDL.h>

namespace lord {
	namespace input {

		enum Key
		{
			KEY_A = 0,
			KEY_B,
			KEY_C,
			KEY_D,
			KEY_E,
			KEY_F,
			KEY_G,
			KEY_H,
			KEY_I,
			KEY_J,
			KEY_K,
			KEY_L,
			KEY_M,
			KEY_N,
			KEY_O,
			KEY_P,
			KEY_Q,
			KEY_R,
			KEY_S,
			KEY_T,
			KEY_U,
			KEY_V,
			KEY_W,
			KEY_X,
			KEY_Y,
			KEY_Z,
			KEY_UP,
			KEY_DOWN,
			KEY_LEFT,
			KEY_RIGHT,
			KEY_SPACE,
			KEY_ENTER,
			KEY_ESCAPE,
			KEY_LCTRL,
			KEY_RCTRL,
			KEY_LALT,
			KEY_RALT,
			KEY_AMOUNT,
			KEY_NULL
		};

		enum KeyState
		{
			KEYSTATE_PRESSED,
			KEYSTATE_TYPED,
			KEYSTATE_RELEASED
		};

		class Input
		{
			bool		_keysPressed[KEY_AMOUNT];
			bool		_keysTyped[KEY_AMOUNT];
			bool		_keysReleased[KEY_AMOUNT];

			int			_mouseX;
			int			_mouseY;
			int			_deltaX;
			int			_deltaY;
		public:
			static inline Input& instance()
			{
				static Input input;
				return input;
			}
			void update();
			bool poll(Key key, KeyState state) const;
			bool poll(Key key) const;
			inline int getMouseX() const { return _mouseX; }
			inline int getMouseY() const { return _mouseY; }
			inline int getMouseDeltaX() const {	return _deltaX; }
			inline int getMouseDeltaY() const {	return _deltaY;	}
		private:
			Input();
			static Key translateSDLKey(SDL_Keycode key);
		};
	}
}