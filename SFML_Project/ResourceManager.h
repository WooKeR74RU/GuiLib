#pragma once

#include <string>
#include <unordered_map>

/*
	Holds all the resources of the game
*/

template<typename Resource>
class ResourceManager
{
public:
	ResourceManager(const std::string& folder, const std::string& extention) :
		m_folder("Resources/" + folder + "/"),
		m_extention("." + extention)
	{ }
	void add(const std::string& name)
	{
		Resource r;
		if (!r.loadFromFile(getFullFilename(name)))
			r.loadFromFile(getFullFilename("fail"));
		m_resources.insert(std::make_pair(name, r));
	}
	bool exists(const std::string& name) const
	{
		return m_resources.find(name) != m_resources.end();
	}
	const Resource& get(const std::string& name)
	{
		if (!exists(name))
			add(name);
		return m_resources.at(name);
	}

private:
	std::string getFullFilename(const std::string& name)
	{
		return m_folder + name + m_extention;
	}
	const std::string m_folder;
	const std::string m_extention;
	std::unordered_map<std::string, Resource> m_resources;
};