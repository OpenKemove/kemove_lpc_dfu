platform(
    name = "lpc_11u35",
    constraint_values = [
        "@platforms//cpu:armv6-m",
        "@platforms//os:none",
    ],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "dfu_elf",
    copts = [
        "-ffreestanding",
        "-nostartfiles",
    ],
    linkopts = [
        "-ffreestanding",
        "-nostartfiles",
    ],
    srcs = [
        "main.c",
    ],
)
