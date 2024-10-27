import { ReleaseObject } from "@hydrogen-web/interfaces";
import {
  Anchor,
  Button,
  Card,
  Group,
  Menu,
  Stack,
  Text,
  Title,
} from "@mantine/core";
import { useMediaQuery, useOs } from "@mantine/hooks";
import {
  IconBrandAndroid,
  IconBrandApple,
  IconBrandWindows,
  IconChevronDown,
  IconDownload,
  IconFunction,
  IconHelp,
  IconStars,
} from "@tabler/icons";
import { useApi } from "hooks/useApi";
import { NextPage } from "next";
import { useEffect, useState } from "react";

const Page: NextPage = () => {
  const { fetch } = useApi();
  const [releases, setReleases] = useState<ReleaseObject[]>();
  const isSmallMobile = useMediaQuery("(max-width: 596px)");
  const isMobile = useMediaQuery("(max-width: 886px)");
  const sysOs = useOs();

  const [os, setOs] = useState("undetermined");
  useEffect(() => {
    if (sysOs) setOs(sysOs);
  }, [sysOs]);

  useEffect(() => {
    fetch<ReleaseObject[]>({
      method: "GET",
      url: "/releases",
    }).then((response) => {
      setReleases(response.data);
    });
  }, []);

  return (
    <Stack
      spacing={30}
      sx={{
        flexGrow: 1,
      }}
    >
      <Stack
        px={10}
        spacing="xs"
        align="center"
        justify="center"
        sx={{
          textAlign: "center",
          minHeight: "45vh",
          flexGrow: 1,
        }}
      >
        <Title
          mt={isSmallMobile ? 20 : undefined}
          size={55}
          variant="gradient"
          weight={700}
          sx={{
            lineHeight: isSmallMobile ? 1 : undefined,
          }}
        >
          Ready to get started?
        </Title>
        <Text
          color="dimmed"
          sx={{
            maxInlineSize: 700,
          }}
        >
          It&apos;s easy! Just click download and our easy-to-use installers
          will guide you through the installation process.{" "}
          {isSmallMobile ? null : (
            <>
              Don&apos;t hesitate to consult our{" "}
              <Anchor color="blue.2">support articles</Anchor> or{" "}
              <Anchor color="blue.2">contact us</Anchor> if you think you need
              help.
            </>
          )}
        </Text>
        <Button
          mt={isSmallMobile ? "lg" : "xl"}
          size={isSmallMobile ? "lg" : "xl"}
          leftIcon={<IconDownload />}
          variant="gradient"
          gradient={
            {
              deg: 90,
              to: "#98bad9",
            } as any
          }
        >
          Download Hydrogen for{" "}
          {releases &&
          releases.map((release) => release.platform).includes(os as any)
            ? {
                undetermined: "Free",
                macos: "macOS",
                ios: "iOS",
                windows: "Windows",
                android: "Android",
                linux: "Free",
              }[os]
            : "Free"}
        </Button>

        <Menu width={300} shadow="md">
          <Menu.Target>
            <Button
              size="xs"
              color="dark"
              variant="subtle"
              rightIcon={<IconChevronDown size={16} />}
            >
              Looking for other downloads?
            </Button>
          </Menu.Target>

          <Menu.Dropdown p={7}>
            {releases &&
              releases.map((release, i) => (
                <Menu.Item
                  key={i}
                  icon={
                    {
                      WINDOWS: <IconBrandWindows size={20} />,
                      ANDROID: <IconBrandAndroid size={20} />,
                      MACOS: <IconBrandApple size={20} />,
                      IOS: <IconBrandApple size={20} />,
                    }[release.platform!]
                  }
                  rightSection={<IconDownload size={20} />}
                  onClick={() => {
                    // window.open(release.url, "_blank");
                  }}
                >
                  {
                    {
                      WINDOWS: "Windows",
                      ANDROID: "Android",
                      MACOS: "macOS",
                      IOS: "iOS",
                    }[release.platform!]
                  }
                  <Text color="dimmed">Release {release.version} (Latest)</Text>
                </Menu.Item>
              ))}
            {/* <Menu.Item
              icon={<IconBrandWindows size={20} />}
              rightSection={<IconDownload size={20} />}
            >
              Windows
              <Text color="dimmed">Release 3.0.2 (Latest)</Text>
            </Menu.Item>
            <Menu.Item
              icon={<IconBrandApple size={20} />}
              rightSection={<IconDownload size={20} />}
            >
              macOS
              <Text color="dimmed">Release 1.4.2 (Latest)</Text>
            </Menu.Item>
            <Menu.Item
              icon={<IconBrandApple size={20} />}
              rightSection={<IconDownload size={20} />}
            >
              iOS
              <Text color="dimmed">Release 3.0.2 (Latest)</Text>
            </Menu.Item>
            <Menu.Item
              icon={<IconBrandAndroid size={20} />}
              rightSection={<IconDownload size={20} />}
            >
              Android
              <Text color="dimmed">Release 1.9.0 (Latest)</Text>
            </Menu.Item> */}
          </Menu.Dropdown>
        </Menu>
        <Text
          color="dimmed"
          size="xs"
          sx={{
            maxInlineSize: 350,
          }}
        >
          By downloading any of the software on this page, you acknowledge that
          you have read and understood, and agree to Hydrogen&apos;s{" "}
          <Anchor component="span" color="dimmed">
            Terms of Service
          </Anchor>{" "}
          and{" "}
          <Anchor component="span" color="dimmed">
            Privacy Policy
          </Anchor>
          .
        </Text>
      </Stack>

      <Group
        px="xl"
        py={50}
        position="apart"
        noWrap={!isMobile}
        sx={{
          borderTop: "1px solid #27272a",
          backgroundColor: "#101010",
        }}
      >
        <Stack>
          <Title size={45} variant="gradient">
            What are you waiting for?
          </Title>
          <Text color="dimmed">
            Take advantage of Hydrogen&apos;s premium script execution platform
            right away. We&apos;ll be with you every step of the way.
          </Text>
          <Group spacing="xs">
            <Button
              variant="gradient"
              gradient={
                {
                  deg: 50,
                  to: "#76a4cf",
                } as any
              }
            >
              Explore Documentation
            </Button>
            <Button variant="subtle">View Premium Plans</Button>
          </Group>
        </Stack>
        <Group noWrap={!isMobile} align="stretch">
          <Card shadow="sm" p="lg" radius="md" withBorder>
            <Stack spacing={10}>
              <IconFunction size={36} />
              <Text weight={500}>Explore Custom Functions</Text>
              <Text
                size="sm"
                color="dimmed"
                sx={{
                  wordBreak: "break-word",
                  maxInlineSize: 1000,
                }}
              >
                Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do
                eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut
                enim ad minim veniam, quis nostrud exercitation ullamco laboris
                nisi ut aliquip ex ea commodo consequat.
              </Text>
            </Stack>

            <Button variant="light" color="blue" fullWidth mt="md" radius="md">
              View Documentation
            </Button>
          </Card>
          <Card shadow="sm" p="lg" radius="md" withBorder>
            <Stack spacing={10}>
              <IconHelp size={36} />
              <Text weight={500}>Join the Discord community</Text>
              <Text
                size="sm"
                color="dimmed"
                sx={{
                  wordBreak: "break-word",
                  maxInlineSize: 1000,
                }}
              >
                Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do
                eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut
                enim ad minim veniam, quis nostrud exercitation ullamco laboris
                nisi ut aliquip ex ea commodo consequat.
              </Text>
            </Stack>

            <Button variant="light" color="blue" fullWidth mt="md" radius="md">
              Join Server
            </Button>
          </Card>
          <Card shadow="sm" p="lg" radius="md" withBorder>
            <Stack spacing={10}>
              <IconStars size={36} />
              <Text weight={500}>Purchase Premium Plan</Text>
              <Text
                size="sm"
                color="dimmed"
                sx={{
                  wordBreak: "break-word",
                  maxInlineSize: 1000,
                }}
              >
                Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do
                eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut
                enim ad minim veniam, quis nostrud exercitation ullamco laboris
                nisi ut aliquip ex ea commodo consequat.
              </Text>
            </Stack>

            <Button variant="light" color="blue" fullWidth mt="md" radius="md">
              View Premium Plans
            </Button>
          </Card>
        </Group>
      </Group>
    </Stack>
  );
};

export default Page;