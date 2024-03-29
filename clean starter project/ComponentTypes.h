/******************************************************************************/
/*!
\file   ComponentTypes.h
\author Hun Yang
\par    email: hun.yang8456@gmail.com
\par    GAM150 demo
\date   2019/04/30


*/
/******************************************************************************/
#pragma once

#include <string>

/**
 * \brief
 * This is enum class for component types
 */
enum class eComponentTypes
{
    INVALID = 0,
    DemoUIButton,
    Player1Controller,
    Player2Controller,
    Player1BoxMove,
    Player2BoxMove,

    NUM_COMPONENTS
};

/**
 * \brief
 * Convert string to eComponentTypes's component
 *
 * \param string
 * String to be  converted for component type
 *
 * \return
 * Converted component type
 */
inline eComponentTypes StringToComponent(const std::string& string)
{
    if (string == "DemoUIButton")
        return eComponentTypes::DemoUIButton;
    if (string == "Player1Controller")
        return eComponentTypes::Player1Controller;
    if (string == "Player2Controller")
        return eComponentTypes::Player2Controller;
    if (string == "Player1BoxMove")
        return eComponentTypes::Player1BoxMove;
    if (string == "Player2BoxMove")
        return eComponentTypes::Player2BoxMove;

    return eComponentTypes::INVALID;
}

/**
 * \brief
 * Convert eComponentTypes's component to string
 *
 * \param type
 * Component type to be converted for string
 *
 * \return
 * Converted string
 */
inline std::string ComponentToString(eComponentTypes type)
{
    if (type == eComponentTypes::DemoUIButton)
        return "DemoUIButton";
    if (type == eComponentTypes::Player1Controller)
        return "Player1Controller";
    if (type == eComponentTypes::Player2Controller)
        return "Player2Controller";
    if (type == eComponentTypes::Player1BoxMove)
        return "Player1BoxMove";
    if (type == eComponentTypes::Player2BoxMove)
        return "Player2BoxMove";

    return "Invalid";
}