# ESP32 PlatformIO CI/CD Workflow

This project tests the use of GitHub Actions to build and generate artifacts (binaries) for ESP32 firmware using PlatformIO.

## Overview

- **Build Environment:** ESP32
- **Tool:** PlatformIO
- **CI/CD:** GitHub Actions

## GitHub Actions Workflow

The workflow file, located in the `.github/workflows` directory, automates the following:
- Installing dependencies
- Building the project with PlatformIO
- Archiving the generated binaries as artifacts

## Getting Started

1. Ensure you have PlatformIO installed.
2. Customize the [PlatformIO configuration](// ...existing code...) as needed.
3. Trigger a build by pushing changes to the repository.

## Tagging and Triggering GitHub Actions

To trigger the PlatformIO workflow on a new version tag, use the following commands in your terminal:

```sh
git tag v1.0.3
git push origin v1.0.3
```

This will create and push the tag `v1.0.3` to your remote repository, triggering the workflow for that tag.

## Artifacts

After a successful build, the firmware binaries for ESP32 are available as downloadable artifacts in the GitHub Actions run details.
