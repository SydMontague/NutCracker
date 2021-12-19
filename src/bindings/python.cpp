#define BOOST_PYTHON_STATIC_LIB 

#include "../core/Actions.h"
#include <boost/python.hpp>

class ScopedGILRelease
{
public:
	inline ScopedGILRelease()
	{
		m_thread_state = PyEval_SaveThread();
	}

	inline ~ScopedGILRelease()
	{
		PyEval_RestoreThread(m_thread_state);
		m_thread_state = NULL;
	}

private:
	PyThreadState* m_thread_state;
};


void _py_Decompile(const std::string& source, const std::string& dest)
{
	ScopedGILRelease scoped;

	std::ofstream stream;
	stream.open(dest);
	if (!stream)
		throw std::exception("Failed to open file");
	Decompile(source.c_str(), NULL, stream);
}

void _py_DecompileFunction(const std::string& source, const std::string& dest, const std::string& debug_function)
{
	ScopedGILRelease scoped;

	std::ofstream stream;
	stream.open(dest);
	if (!stream)
		throw std::exception("Failed to open file");
	Decompile(source.c_str(), debug_function.c_str(), stream);
}

//BOOST_PYTHON_FUNCTION_OVERLOADS(_py_Decompile_overloads, _py_Decompile, 2, 3)


BOOST_PYTHON_MODULE(NutCracker)
{
	using namespace boost::python;

	def("decompile", &_py_Decompile);// , _py_Decompile_overloads((arg("source"), arg("debug_function") = "")));
	def("decompileFunction", &_py_DecompileFunction);
}
