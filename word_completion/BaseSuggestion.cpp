#include "BaseSuggestion.h"

BaseSuggestion::BaseSuggestion() {}

BaseSuggestion::BaseSuggestion(std::string path, ulong c)
{
	pathToDict = path;
	count = c;
}
