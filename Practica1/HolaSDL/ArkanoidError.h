#ifndef ARKANOIDERROR_H_
#define ARKANOIDERROR_H_

#include <stdexcept>
#include <sstream>
#include <stdlib.h>
#include <SDL_error.h>
#include <SDL_image.h>


using namespace std;

class ArkanoidError :
	public logic_error
{
public:
	ArkanoidError(const string& m) : logic_error("Arkanoid error." + m) {};	
};
#endif // !ARKANOIDERROR_H_

#ifndef SDLERROR_H_
#define SDLERROR_H_

class SDLError :
	public ArkanoidError
{
public:
	SDLError(const string& m) : ArkanoidError(m + "SDL error.") {};

	SDLError SDL_GetError() {};
	SDLError IMG_GetError() {};
};
#endif // !SDLERROR_H_
#ifndef FILENOTFOUND_H_
#define FILENOTFOUND_H_

class FileNotFoundError :
	public ArkanoidError
{
public:
	FileNotFoundError(const string& m) : ArkanoidError(m + "FileNotFound Error.") {};

};
#endif // !FILENOTFOUND_H_


#ifndef FILEFORMATERROR_H_
#define FILEFORMATERROR_H_

class FileFormatError :
	public ArkanoidError
{
public:
	FileFormatError(const string& m) : ArkanoidError(m + "FileFormat Error.") {};


};
#endif // !FILEFORMATERROR_H_


