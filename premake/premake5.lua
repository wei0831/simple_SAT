--[[
/******************************************************************************/
/*!
 \file   premake5.lua
 \author Jack Chang
 \par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
]]

solution "SAT_Collision"
  configurations { "Debug", "Release" }
  location "../"
  
project "SAT_Collision"
  targetname "SAT_Collision"
  location "../build/"
  language "C++"
  objdir "../build/obj"
  kind "ConsoleApp"

  -- source files
  files
  {
    "../source/**.h",
    "../source/**.cpp"
  }
  
  includedirs
  { 
    "../source",
    "../source/**"
  }
  
  libdirs
  { 

  }

  configuration "Debug"
    flags { "Symbols" }
    defines { "_DEBUG", "_CRT_SECURE_NO_WARNINGS" }
    links 
    { 

    }
    targetdir "../build/bin/debug"
    postbuildcommands
    { 

    }

  configuration "Release"
    flags { "Symbols" }
    optimize "Full"
    defines { "NDEBUG", "_CRT_SECURE_NO_WARNINGS" }
    links
    { 

    }
    targetdir "../build/bin/release"
    postbuildcommands 
    { 

    }
      