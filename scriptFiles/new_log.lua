-- A small example of how to use classes and global variables in Lua.

function new_log()
    local self = {logs = ""}
    setmetatable(self, {
        __index = {
            log = function (tab, val)
                tab.logs = tab.logs .. val .. "\n\r"
            end,
            out = function(tab)
                return tab.logs
            end
        }
    })
    return self
end

x = new_log()

x:log(_VERSION)

x:log("\nGlobal variables:")
for k, v in pairs(_G) do
    x:log(k);
end

x:log("\nArguments:")
for k, v in pairs(arg) do
    x:log(v);
end

print(x:out())
