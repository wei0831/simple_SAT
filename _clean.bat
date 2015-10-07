GOTO EndComment
/******************************************************************************/
/*!
 \file   _clean.bat
 \author Jack Chang
 \date   09/01/2014
 \par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
    Clear all unneeded files
 */
/******************************************************************************/
:EndComment

@echo off
rmdir /S /Q build
rm *.sdf
rm *.opensdf
rm *.sln
rm *.suo
