#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

class GameObject
{
public:
	GameObject() {};
	virtual ~GameObject() {};
	
	virtual void Render() const = 0;
	virtual void Update() = 0;
	virtual void handleEvents() = 0;
};
#endif // !GAMEOBJECT_H_

