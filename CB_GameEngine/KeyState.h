#pragma once

/// <summary>
/// 키의 상태를 나타내는 열거형입니다.
///	가장 하위 비트는 현재 프레임에 키가 눌려있었던 상태인지를 나타내고,
///	밑에서 2번째 비트는 이전 프레임에 키가 눌려있었던 상태인지를 나타냅니다.
///	밑에서 3, 4, 5번째 비트는 각각 Down, Up, Hold 상태인지를 나타냅니다.
/// </summary>
enum class KeyState
{
	// 키가 전 프레임는 눌려 있었고, 현 프레임에 올라온 경우입니다.
	Up = 0b01010,
	// 키가 전 프레임에는 올라와 있었고, 현 프레임에 눌려진 경우입니다.
	Down = 0b00101,
	// 키가 전 프레임에도 눌려 있었고, 현 프레임에도 눌려져있는 경우입니다.
	Hold = 0b10011,
	// 키가 전 프레임에도 올라와 있었고, 현 프레임에도 올라와있는 경우입니다.
	None = 0b00000,
};
