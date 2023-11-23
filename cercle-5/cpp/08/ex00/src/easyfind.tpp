
template <typename T>
void easyfind(const T& container, int n) {
    if (std::find(container.begin(), container.end(), n) != container.end())
        std::cout << n << " is in this container." << std::endl;
    else
        throw OccurrenceNotFoundException();
}