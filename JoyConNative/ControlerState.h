#pragma once
#define Y_MAP 0b0000'0001'0000'0000'0000'0000
#define X_MAP 0b0000'0010'0000'0000'0000'0000
#define B_MAP 0b0000'0100'0000'0000'0000'0000
#define A_MAP 0b0000'1000'0000'0000'0000'0000
#define SRRIGHT_MAP 0b0001'0000'0000'0000'0000'0000
#define SLRIGHT_MAP 0b0010'0000'0000'0000'0000'0000
#define R_MAP 0b0100'0001'0000'0000'0000'0000
#define ZR_MAP 0b100'0000'0000'0000'0000'0000
#define MINUS_MAP 0b000'0000'0000'0001'0000'0000
#define PLUS_MAP 0b000'0000'0000'0010'0000'0000
#define RSTICK_MAP 0b000'0000'0000'0100'0000'0000
#define LSTICK_MAP 0b000'0000'0000'1000'0000'0000
#define HOME_MAP 0b000'0000'0001'0000'0000'0000
#define CAPTURE_MAP 0b000'0000'0010'0000'0000'0000
#define CHARGING_GRIP_MAP 0b000'0000'1000'0000'0000'0000
#define DOWN_MAP 0b000'0000'0000'0000'0000'0001
#define UP_MAP 0b000'0000'0000'0000'0000'0010
#define RIGHT_MAP 0b000'0000'0000'0000'0000'0100
#define LEFT_MAP 0b000'0000'0000'0000'0000'1000
#define SRLEFT_MAP 0b000'0000'0000'0000'0001'0000
#define SLLEFT_MAP 0b000'0000'0000'0000'0010'0000
#define L_MAP 0b000'0000'0000'0000'0100'0000
#define ZL_MAP 0b000'0000'0000'0000'1000'0000
using namespace System::Numerics;
namespace JoyConNative {

	public enum class BateryState {
		Full,
		Medium,
		Low,
		Empty,
		Charging
	};

	public value class ControlerState
	{
	public:

		property BateryState Batery {
			BateryState get() {
				return bateryState;
			}
		}

		property bool Y {
			bool get() {
				return buttonState & Y_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= Y_MAP;
			else
				buttonState &= ~Y_MAP;
		}
		}

		property bool X {
			bool get() {
				return buttonState & X_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= X_MAP;
			else
				buttonState &= ~X_MAP;
		}
		}

		property bool B {
			bool get() {
				return buttonState & B_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= B_MAP;
			else
				buttonState &= ~B_MAP;
		}
		}

		property bool A {
			bool get() {
				return buttonState & A_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= A_MAP;
			else
				buttonState &= ~A_MAP;
		}
		}

		property bool SRRight {
			bool get() {
				return buttonState & SRRIGHT_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= SRRIGHT_MAP;
			else
				buttonState &= ~SRRIGHT_MAP;
		}
		}

		property bool SLRight {
			bool get() {
				return buttonState & SLRIGHT_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= SLRIGHT_MAP;
			else
				buttonState &= ~SLRIGHT_MAP;
		}
		}

		property bool R {
			bool get() {
				return buttonState & R_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= R_MAP;
			else
				buttonState &= ~R_MAP;
		}
		}

		property bool ZR {
			bool get() {
				return buttonState & ZR_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= ZR_MAP;
			else
				buttonState &= ~ZR_MAP;
		}
		}

		property bool Minus {
			bool get() {
				return buttonState & MINUS_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= MINUS_MAP;
			else
				buttonState &= ~MINUS_MAP;
		}
		}

		property bool Plus {
			bool get() {
				return buttonState & PLUS_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= PLUS_MAP;
			else
				buttonState &= ~PLUS_MAP;
		}
		}

		property bool RStick {
			bool get() {
				return buttonState & RSTICK_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= RSTICK_MAP;
			else
				buttonState &= ~RSTICK_MAP;
		}
		}

		property bool LStick {
			bool get() {
				return buttonState & LSTICK_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= LSTICK_MAP;
			else
				buttonState &= ~LSTICK_MAP;
		}
		}

		property bool Home {
			bool get() {
				return buttonState & HOME_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= HOME_MAP;
			else
				buttonState &= ~HOME_MAP;
		}
		}

		property bool Capture {
			bool get() {
				return buttonState & CAPTURE_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= CAPTURE_MAP;
			else
				buttonState &= ~CAPTURE_MAP;
		}
		}

		property bool ChargingGrip {
			bool get() {
				return buttonState & CHARGING_GRIP_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= CHARGING_GRIP_MAP;
			else
				buttonState &= ~CHARGING_GRIP_MAP;
		}
		}


		property bool Down {
			bool get() {
				return buttonState & DOWN_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= DOWN_MAP;
			else
				buttonState &= ~DOWN_MAP;
		}
		}

		property bool Up {
			bool get() {
				return buttonState & UP_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= UP_MAP;
			else
				buttonState &= ~UP_MAP;
		}
		}

		property bool Right {
			bool get() {
				return buttonState & RIGHT_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= RIGHT_MAP;
			else
				buttonState &= ~RIGHT_MAP;
		}
		}

		property bool Left {
			bool get() {
				return buttonState & LEFT_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= LEFT_MAP;
			else
				buttonState &= ~LEFT_MAP;
		}
		}

		property bool SRLeft {
			bool get() {
				return buttonState & SRLEFT_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= SRLEFT_MAP;
			else
				buttonState &= ~SRLEFT_MAP;
		}
		}

		property bool SLLeft {
			bool get() {
				return buttonState & SLLEFT_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= SLLEFT_MAP;
			else
				buttonState &= ~SLLEFT_MAP;
		}
		}

		property bool L {
			bool get() {
				return buttonState & L_MAP;
			}
	internal:
		void set(bool value) {
			if (value)
				buttonState |= L_MAP;
			else
				buttonState &= ~L_MAP;
		}
		}

		property bool ZL {
			bool get() {
				return buttonState & ZL_MAP;
			}
		internal:
			void set(bool value) {
				if (value)
					buttonState |= ZL_MAP;
				else
					buttonState &= ~ZL_MAP;
			}
		}

		property Vector2 LeftStick {
			Vector2 get() {
				return leftStick;
			}
		internal:
			void set(Vector2 value) {
				leftStick = value;
			}
		}
		property Vector2 RightStick {
			Vector2 get() {
				return rightStick;
			}
		internal:
			void set(Vector2 value) {
				rightStick = value;
			}
		}

		DWORD buttonState;

	private:
		BateryState bateryState;
		System::Numerics::Vector2 leftStick;
		System::Numerics::Vector2 rightStick;
	};

}