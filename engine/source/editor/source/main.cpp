#include <filesystem>

#include <editor/include/editor.h>
#include <runtime/engine.h>

int main(int argc, char** argv)
{
    // new engine
    // engine.config()
    // engine.init()
    // engine.run()
    // engine.clear()
    // engine.shutdown()
    // int res = inno::visualizeDistribution();
    std::filesystem::path executable_path(argv[0]);
    std::filesystem::path config_file_path = executable_path.parent_path() / "InnoEditor.ini";

    inno::InnoEngine* engine = new inno::InnoEngine();
    engine->startEngine(config_file_path.generic_string());

    // engine->clear();
    // engine->shutdownEngine();

    return 0;
}