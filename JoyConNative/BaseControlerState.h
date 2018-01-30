#pragma once

#include "ForwardDeclarations.h"
#include "HCIState.h"

namespace JoyConNative {

	/// <summary>
	/// This class will handle the different input modes a controler can has. e.g. 
	/// </summary>
	ref class BaseControlerState abstract
	{
	public:
		BaseControlerState(JoyConNative::Controler^ controler);
		virtual	~BaseControlerState();
		!BaseControlerState();

		/// <summary>
		/// Will be called once when this state will be used.
		/// </summary>
		void Enter();

		/// <summary>
		/// After this call and only if, it is assumed that the public controler state (Buttons etc.) was updated.
		/// </summary>
		void Update(System::TimeSpan &epelapsedTime);
		/// <summary>
		/// This method will called after the last update. clean up everything you no lonver needs.
		/// </summary>
		void Leave();

	internal:
		virtual void SetHCIState(HCIState state);


	protected:
		/// <summary>
		/// Will be called once when this state will be used.
		/// </summary>
		virtual void OnEnter() abstract;
		/// <summary>
		/// After this call and only if, it is assumed that the public controler state (Buttons etc.) was updated.
		/// </summary>
		virtual void OnUpdate(System::TimeSpan &epelapsedTime) abstract;
		/// <summary>
		/// This method will called after the last update. clean up everything you no lonver needs.
		/// </summary>
		virtual void OnLeave() abstract;

		property Controler^ Controler {
			JoyConNative::Controler^ get() {
				return controler;
			}
		}

	private:
		bool isActive;
		initonly JoyConNative::Controler^ controler;
	};

}
