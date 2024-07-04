import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_NAME, CONF_OPTIONS
from esphome.components import select

oled_select_menu_ns = cg.esphome_ns.namespace('oled_select_menu')
OledSelectMenu = oled_select_menu_ns.class_("OledSelectMenu",
    select.Select, cg.PollingComponent                             
)

def ensure_option_map(value):
    cv.check_not_templatable(value)
    option = cv.All(cv.int_range(1, 9))
    mapping = cv.All(cv.string_strict)
    options_map_schema = cv.Schema({option: mapping})
    value = options_map_schema(value)

    all_values = list(value.keys())
    unique_values = set(value.keys())
    if len(all_values) != len(unique_values):
        raise cv.Invalid("Mapping values must be unique.")

    return value

CONFIG_SCHEMA = select.select_schema(OledSelectMenu).extend(
    {
        cv.Required(CONF_OPTIONS): ensure_option_map
    }
)


#CONF_OLED_MENU = "OledMenu"
#CONF_MENUS = "menus"
#CONF_SELECT = "select"

#SELECT_MENUS = cv.Schema({
#   cv.Required(CONF_NAME): cv.string,
#   cv.Required(CONF_SELECT): cv.string
#})

#CONFIG_SCHEMA = cv.Schema({
#    cv.GenerateID(): cv.declare_id(OledMenuComponent),
#    cv.Required(CONF_MENUS): cv.ensure_list(SELECT_MENUS)
#})

def to_code(config):
    pass