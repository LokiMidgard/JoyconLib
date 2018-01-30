#pragma once
#include "BaseControlerState.h"
namespace JoyConNative {
	ref class SimpleHIDState : public BaseControlerState
	{
	public:
		SimpleHIDState(JoyConNative::Controler^ controler);

	protected:
		/// <summary>
		/// Will be called once when this state will be used.
		/// </summary>
		virtual void OnEnter() override;
		/// <summary>
		/// After this call and only if, it is assumed that the public controler state (Buttons etc.) was updated.
		/// </summary>
		virtual void OnUpdate(System::TimeSpan &epelapsedTime)  override;
		/// <summary>
		/// This method will called after the last update. clean up everything you no lonver needs.
		/// </summary>
		virtual void OnLeave()  override;
	};
}
