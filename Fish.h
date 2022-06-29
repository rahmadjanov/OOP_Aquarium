#pragma once
#include <string>
#include <vector>

using namespace std;

class fish_all {
public:
	/* Значения переменной type: 0 - рыба 1 - улитка 2 - камень 3 - водоросли*/
	int type;
	fish_all(int v_type) : type(v_type) {};
	~fish_all() {};
	virtual void SetHealth(int v) {};
	virtual void SetHealthM(int v) {};
	virtual void SetState(string state) {};
	virtual string GetName() { return "0"; };
	virtual string GetType() { return "0"; };
	virtual string GetColor() { return "0"; };
	virtual string GetState() { return "0"; };
	virtual int GetHealth() { return 0; };
	virtual int GetMud() { return 0; };
};

class fish : fish_all
{
private:
	string state;
	string name;
	string type;
	int health;
	int mud;
public:
	fish(string v_name, int v_health, int v_mud, string v_type, string v_state) 
		: name(v_name), health(v_health), mud(v_mud), type(v_type), state(v_state), fish_all(0) {}
	~fish() {}
	void SetHealth(int v) { health = v; }
	void SetHealthM(int v) { health += v; }
	void SetState(string state) { this->state = state; }
	string GetName() { return name; }
	string GetType() { return type; }
	string GetState() { return state; }
	int GetHealth() { return health; }
	int GetMud() { return mud; }
};

class snail : fish_all {
protected:
	string name;
	string type;
	int health;
	int mud;
public:
	snail(string v_name, int v_health, string v_type, int v_mud) 
		: name(v_name), health(v_health), type(v_type), mud(v_mud), fish_all(1) {}
	~snail() {}
	void SetHealth(int v) { health = v; }
	void SetHealthM(int v) { health += v; }
	string GetName() { return name; }
	string GetType() { return type; }
	int GetHealth() { return health; }
	int GetMud() { return mud; }
};

class decor : fish_all {
protected:
	string type;
	string color;
public:
	decor(string v_color, string v_type, int p_type) 
		: color(v_color), type(v_type), fish_all(p_type) {}
	~decor() {}
	string GetType() { return type; }
	string GetColor() { return  color; }
	void SetColor(string color) { this->color = color; }
};

class feed {
protected:
	string type;
	string name;
	int nutritional_value = 0;
	int mud = 0;
public:
	string GetType() { return type; };
	string GetName() { return name; };
	int GetNutritionalValue() { return nutritional_value; };
	int GetMud() { return mud; }
};

class Sticks :public feed {
public:
	Sticks() { type = "сухой корм-палочки"; name = "Sticks"; nutritional_value = 2; mud = 4; }
};

class TetraMin :public feed {
public:
	TetraMin() { type = "сухой корм-хлопья"; name = "TetraMin"; nutritional_value = 4; mud = 8; }
};

class Mud {
	int mud;
public:
	Mud() { mud = 40; }
	void SetMud(int mud) { this->mud = mud; }
	void SetMudFrom(int mud) { this->mud += mud; }
	int GetMud() { return mud; }
};

class Aquarium {
public:
	int fish_number = 0, snail_number = 0, decor_number = 0;
	vector <fish_all*> fsh;
	Mud A_MUD;
	void Add(fish_all* fish) {
		fsh.push_back(fish);
	}
	void Remove(int position) {
		fsh.erase(fsh.begin() + position);
	}

	void Damage_fish() {
		if (A_MUD.GetMud() > 400) {
			for (auto obj : fsh) {
				if (obj->type == 0)
					obj->SetHealthM(A_MUD.GetMud()%100 * -1);
			}
		}
		else {
			for (auto obj : fsh) {
				if (obj->type == 0)
					obj->SetHealthM(-1);
			}
		}
	}
};