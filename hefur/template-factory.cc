#include "template-factory.hh"
#include "options.hh"
#include "log.hh"

namespace hefur
{
  mt::Template::ConstPtr
  TemplateFactory::create(const char *path)
  {
    char real_path[PATH_MAX];

    snprintf(real_path, sizeof (real_path), "%s/tpl/%s", WWW_DIR.c_str(), path);
    auto value = cache_.get(real_path);
    if (!value->get())
      log->error("failed to load template file %s", real_path);
    return value->get();
  }
}
